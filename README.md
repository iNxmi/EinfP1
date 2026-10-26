# EinfP1 Master Repository

Central repository for managing university programming exercises, upstream synchronization, and automated submission builds.

---

## Exercise Management

Both scripts accept exercise numbers in single-digit, zero-padded, or prefixed formats (e.g., `1`, `01`, `uebung01`).

### Adding an Exercise
Imports the upstream exercise repository as a subtree into `exercises/uebung<ID>` and cleans up boilerplate files:

```bash
./scripts/create.sh <ID>
```

### Updating an Exercise
Pulls the latest changes from the university upstream remote into the local subtree:

```bash
./scripts/update.sh <ID>
```

---

## Submissions & Releases

Submissions are packaged automatically via GitHub Actions:

1. Draft a new release on GitHub.
2. Set the tag to the exercise identifier (e.g., `v1`, `01`, or `uebung01`).
3. Publish the release.

The workflow bundles all solution files (`.c`, `.h`, `.txt`) along with `library/matrikelnummern.txt` and attaches the resulting `<matnr1>_<matnr2>.tar.gz` archive directly to the release assets.
