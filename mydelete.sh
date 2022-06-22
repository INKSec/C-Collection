#!/bin/bash
# Löschen  aller Dateien im Ordner nach vorheriger Abfrage
#Michael Burkhardt 22.10.2021
# a)
#Füge alle Dateien im Ordner der Variablen zu
files=(*)
#Frage für jede Datei im Array, ob die Datei gelöscht werden soll 
for f in "${files[@]}"
do
echo "Wollen Sie die Datei: $f löschen?"
read reply
#Wenn "y" wird die Datei gelöscht
if [ $reply = y ]
then
rm "$f"
echo "removed $f"
#Wenn "nein" wird das Nächste Objekt angefragt
elif [ $reply != y ]; then continue
fi
done

#Die Probleme im Labor am Freitag kamen daher, dass ich in der if Abfrage keine Lerzeichen hatte.
#Falsch if [$reply=y]
#Richtig if [ $reply = y ]

# b)Das Script kann über das Kommando chmod -x <scriptname> ausführbar gemacht werden

# c) export PATH=$PATH:$(pwd) stellt sicher, dass immmer das aktuelle Verzeichnis zu PATH hinzugefügt wird.
# Dies scheint jedoch ein Sicherheitsrisiko zu sein. Quelle: 
#https://stackoverflow.com/questions/27188856/adding-any-current-directory-to-the-search-path-in-linux#:~:text=If%20you%20want%20to%20permanently%20add%20the%20directory,the%20expansion%20of%20%24PATH%20to%20its%20current%20value.