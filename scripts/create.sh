#!/bin/sh
set -e

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
git subtree add --prefix="$PREFIX" "$REMOTE_NAME" master --squash
