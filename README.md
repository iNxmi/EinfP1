# EinfP1 Master Repository

Central repository for managing university programming exercises, upstream synchronization, and automated submission builds.

- **Moodle Course:** [Einführung in die Programmierung I (TU Darmstadt)](https://moodle.tu-darmstadt.de/course/view.php?id=50666)

---

## How to pass this module

There are 7 exercise sheets.

To pass, the following requirements must be met:
- Achieve at least 50% of the total regular points overall.
- Score at least 20% on at least 6 exercise sheets each.
- 2 – 3 testates (Testate)
- Registration in TuCAN by mid-November
- Every submission must contain the files "matrikelnummern.txt" (with all group members and GitLab IDs) and "erklaerung.txt" (documenting all resources and AI used) in the root directory, otherwise 0 points will be awarded.


## Submissions & Releases

Submissions are packaged automatically via GitHub Actions:

1. Draft a new release on GitHub.
2. Set the tag to the format `vX.X`, where the first number matches the exercise sheet (e.g., `v1.0` or `v1.1` for `uebung01`). Other tag formats will fail and delete the release.
3. Publish the release.

The workflow bundles all solution files (`.c`, `.h`, `.txt`) along with `library/matrikelnummern.txt` and attaches the resulting `<matnr1>_<matnr2>.tar.gz` archive directly to the release assets.
