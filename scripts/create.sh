#!/bin/sh
set -e

SCRIPT_TAG="[create.sh]"

if [ -z "$1" ]; then
  echo "Usage: $0 <exercise_number> (e.g., $0 1)" >&2
  exit 1
fi

# Format number to two digits (1 -> 01, 10 -> 10)
NUM=$(printf "%02d" "$1")
PREFIX="exercises/uebung$NUM"
REMOTE_NAME="upstream_uebung$NUM"
REPO_URL="https://programmierung2026:glpat-BbdmmWHW74cJv0dhV1Ex5m86MQp1OjFuZwk.01.0z0uhfxhl@gitlab.hefdi.de/tuda/einf_prog_i/2026/material/tutorials/uebung$NUM.git"

# Add remote if not already present
if ! git remote | grep -q "^${REMOTE_NAME}$"; then
  git remote add "$REMOTE_NAME" "$REPO_URL"
fi

# Add subtree
git subtree add --prefix="$PREFIX" --message="$SCRIPT_TAG Add subtree for $PREFIX" "$REMOTE_NAME" master --squash

# Remove matrikelnummern.txt if present
if [ -f "$PREFIX/matrikelnummern.txt" ]; then
  git rm -f "$PREFIX/matrikelnummern.txt"
fi

# Ensure erklaerung.txt exists and is empty
: > "$PREFIX/erklaerung.txt"
git add "$PREFIX/erklaerung.txt"

# Handle loesung_zu_abgabe_umwandeln.sh
TARGET_SH="$PREFIX/loesung_zu_abgabe_umwandeln.sh"
LIB_SH="library/loesung_zu_abgabe_umwandeln.sh"

if [ -f "$TARGET_SH" ]; then
  if [ -f "$LIB_SH" ]; then
    if cmp -s "$TARGET_SH" "$LIB_SH"; then
      git rm -f "$TARGET_SH"
    else
      echo "Warning: $TARGET_SH differs from $LIB_SH. Keeping the upstream file." >&2
    fi
  else
    echo "Warning: $LIB_SH not found to compare. Keeping $TARGET_SH." >&2
  fi
fi

# Commit changes if staged
if ! git diff --cached --quiet; then
  git commit -m "$SCRIPT_TAG Cleanup boilerplate files from $PREFIX"
fi
