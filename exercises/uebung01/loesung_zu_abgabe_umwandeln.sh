#!/usr/bin/env bash
# Aufruf: ./loesung_zu_abgabe_umwandeln.sh [verzeichnis]
# Erzeugt <matnr1>_<matnr2>_....tar.gz im aktuellen Verzeichnis.
set -euo pipefail

dir="${1:-.}"

if [[ ! -d "$dir" ]]; then
    echo "Fehler: '$dir' ist kein Verzeichnis" >&2
    exit 1
fi

for f in matrikelnummern.txt erklaerung.txt; do
    if [[ ! -f "$dir/$f" ]]; then
        echo "Fehler: '$dir/$f' nicht gefunden" >&2
        exit 1
    fi
done

# Matrikelnummern aus der Datei einlesen und zu einem Basisnamen zusammenfügen
# Matrikelnummern sollten der erste Wert jeder Zeile sein
base=""
while IFS=',' read -r matnr _rest || [[ -n "$matnr" ]]; do
    matnr="${matnr//[[:space:]]/}"
    # Leere Zeilen und Kommentarzeilen (#) überspringen
    [[ -z "$matnr" || "$matnr" == \#* ]] && continue
    base="${base:+${base}_}${matnr}"
done < "$dir/matrikelnummern.txt"

if [[ -z "$base" ]]; then
    echo "Fehler: keine Matrikelnummern in $dir/matrikelnummern.txt gefunden" >&2
    exit 1
fi

out="$(pwd)/${base}.tar.gz"
parent="$(cd "$dir/.." && pwd)"
name="$(basename "$(cd "$dir" && pwd)")"

# Archivieren der Dateien im Verzeichnis
# Verzeichnis wird als oberstes Verzeichnis im Archiv beibehalten
# Nur Dateien mit den Endungen .txt, .c und .h werden ins Archiv aufgenommen
(cd "$parent" && find "$name" -type f \( -name '*.txt' -o -name '*.c' -o -name '*.h' \) -print0 \
    | tar -czf "$out" --null -T -)

echo "$out erstellt. Diese Datei muss jetzt ueber moodle eingereicht werden."
