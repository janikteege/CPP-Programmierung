In dieser Aufgabe sollst Du den Umgang mit Zeigern/Pointern üben. Lies mit std::cin eine beliebige Anzahl von doubles in ein dynamisch allokiertes Array ein. Dabei musst Du eventuell die Größe des Arrays zur Laufzeit ändern, wenn es voll ist. Sobald der Benutzer etwas eingibt, was keine Zahl ist, wird die Eingabe beendet.

Nach dem erfolgreichen Einlesen des dynamischen Arrays sollst Du auch damit arbeiten. Lies ähnlich wie im ersten Schritt genau so viele Indizes (int) ein, wie der Benutzer Werte eingegeben hat. Diese Indizes sollen eine neue Reihenfolge (Permutation) der Daten beschreiben.

Überprüfe zunächst, ob die eingegebenen Indizes eine korrekte Permutation beschreiben. Implementiere dazu die Funktion bool isPermutation(int* perm, int count) und rufe sie auf. Die Funktion ist in utils.hpp deklariert und soll in utils.cpp definiert werden.

Wenn die Permutation korrekt ist, sollst Du überprüfen, ob eine Umsortierung der Daten des dynamischen Arrays mit der angegebenen Permutation eine aufsteigend sortierte Folge ergibt. Implementiere dazu die Funktion bool isSorted(double* data, int count, int* perm), die ebenfalls in utils.hpp deklariert ist. Diese Funktion soll die Daten der eingegebenen Arrays nicht verändern und nicht kopieren!

⚠ Ab nächster Woche werden wir nur noch Einreichungen akzeptieren, die keine Warnings beim Kompilieren erzeugen, wobei wir die GCC Optionen -Wall und -pedantic voraussetzen. – Am besten, Du versuchst schon diese Woche, das einzuhalten.

Hinweise
Für eine gültige Permutation muss jeder Index zwischen 0 und N-1 genau einmal vorkommen.
Um herauszufinden, ob etwas eingegeben wurde, das keine Zahl ist, kannst Du die Funktion std::cin.fail() verwenden. (std::cin ist ein Input Stream. Weitere Informationen dazu findest Du hier)
Da Du danach weiter mit std::cin arbeiten willst, musst Du es mit Hilfe von std::cin.clear() vom Fehler- wieder in den Grundzustand versetzen und mit std::cin.ignore() das falsche Zeichen überspringen
Du kannst so viele zusätzliche Funktionen schreiben, wie Du benötigst.