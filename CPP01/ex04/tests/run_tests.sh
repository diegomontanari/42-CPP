#!/bin/sh
# Test dell'ex04: lancia ./replace su alcuni casi e confronta col risultato atteso.
# Uso: dalla cartella ex04, "make && sh tests/run_tests.sh"
cd "$(dirname "$0")/.." || exit 1
ok=0; ko=0
check() { # nome, file_ottenuto, testo_atteso
	if [ "$(cat "$2")" = "$3" ]; then echo "OK  $1"; ok=$((ok+1)); else echo "KO  $1"; ko=$((ko+1)); fi
}

./replace tests/saluti.txt ciao salve
check "parola semplice" tests/saluti.txt.replace "$(printf 'salve Mario\nsalve salve Luigi\nniente da cambiare qui')"

./replace tests/aaaa.txt aa b
check "occorrenze attaccate (aaaa, aa -> b)" tests/aaaa.txt.replace "bb"

./replace tests/saluti.txt ciao ""
check "s2 vuota cancella s1" tests/saluti.txt.replace "$(printf ' Mario\n  Luigi\nniente da cambiare qui')"

./replace tests/vuoto.txt ciao salve
check "file vuoto" tests/vuoto.txt.replace ""

./replace tests/saluti.txt Mario Mario
check "s1 uguale a s2" tests/saluti.txt.replace "$(cat tests/saluti.txt)"

./replace tests/non_esiste.txt a b 2>/dev/null && { echo "KO  file inesistente"; ko=$((ko+1)); } || { echo "OK  file inesistente da errore"; ok=$((ok+1)); }
./replace tests/saluti.txt "" b 2>/dev/null && { echo "KO  s1 vuota"; ko=$((ko+1)); } || { echo "OK  s1 vuota da errore"; ok=$((ok+1)); }
./replace tests/saluti.txt a 2>/dev/null && { echo "KO  argomenti sbagliati"; ko=$((ko+1)); } || { echo "OK  argomenti sbagliati danno errore"; ok=$((ok+1)); }

rm -f tests/*.replace
echo "Superati: $ok, falliti: $ko"
