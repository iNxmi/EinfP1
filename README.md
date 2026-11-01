# EinfP1 Master Repository

Central repository for managing university programming exercises, upstream synchronization, and automated submission
builds.

* **Moodle
  Course:** [Einführung in die Programmierung I (TU Darmstadt)](https://moodle.tu-darmstadt.de/course/view.php?id=50666)

---

## How to pass this module V2

There are 7 exercise sheets.

To pass, the following requirements must be met:
- Achieve at least 50% of the total regular points overall.
- Score at least 20% on at least 6 exercise sheets each.
- 2 – 3 testates (Testate)
- Registration in TuCAN by mid-November
- Every submission must contain the files "matrikelnummern.txt" (with all group members and GitLab IDs) and "erklaerung.txt" (documenting all resources and AI used) in the root directory, otherwise 0 points will be awarded.

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

The workflow bundles all solution files (`.c`, `.h`, `.txt`) along with `library/matrikelnummern.txt` and attaches the
resulting `<matnr1>_<matnr2>.tar.gz` archive directly to the release assets.
