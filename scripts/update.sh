#!/bin/sh
set -e

if [ -z "$1" ]; then
  echo "Usage: $0 <exercise_number> (e.g., $0 1)" >&2
  exit 1
fi

NUM=$(printf "%02d" "$1")
PREFIX="exercises/uebung$NUM"
REMOTE_NAME="upstream_uebung$NUM"

# Pull updates into subtree
git subtree pull --prefix="$PREFIX" "$REMOTE_NAME" master --squash
