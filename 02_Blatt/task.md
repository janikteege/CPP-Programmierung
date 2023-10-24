Assignment 2 - Rock, Paper, Scissors
Schreibe ein Schere-Stein-Papier-Spiel.

Dazu soll der Spieler eine Zahl auf der Kommandozeile eingeben, um seine Wahl festzulegen. 1 ist Stein (Rock), 2 ist Papier (Paper), 3 ist Schere (Scissors). Danach wird gespielt. Das Programm soll eine zweite Wahl generieren und bestimmen, ob der Spieler gewonnen hat, oder nicht.

Schere gewinnt gegen Papier, Papier gewinnt gegen Stein, Stein gewinnt gegen Schere. Bei Unentschieden wird nochmal gespielt.

Wir haben bereits die main()-Funktion vorgegeben, in der der Spieler einen Spielmodus auswählen kann und das Ergebnis ausgegeben wird. Du sollst die Funktionen beats(int, int), play(), bestOf3() und bestOf5() implementieren, in denen die Spiellogik versteckt ist.

Was diese Funktionen genau machen sollen, ist in den Kommentaren in der Template-Datei beschrieben. Du darfst annehmen, dass der Benutzer keine ungültigen Eingaben macht.

Um ein faires Spiel zu schreiben, bietet es sich an, eine Zufallszahl zwischen 1 und 3 zu generieren. Zur Erzeugung von Zufallszahlen in C/C++ siehe z.B. hier

Schreibe deine Ausgaben nach std::cout und lies die Nutzereingaben aus std::cin!

Schau Dir den vorgegebenen Code an. Manches davon kannst Du so ähnlich vielleicht auch brauchen, um die gefragten Funktionen zu implementieren.

Um ein Programm übersichtlich zu halten und duplizierten Code zu vermeiden, ist es oft sinnvoll, es in mehrere Funktionen aufzuteilen, die sich gegenseitig aufrufen. Wir haben bereits mehrere Funktionen vorgegeben. Das Aufrufen musst du erledigen…

Du darfst natürlich gern weitere Funktionen definieren, wenn es Dir hilft.