# Problema 1

Să se creeze tipul abstract de date (structura) – monitor, care are denumirea firmei producătoare, dimensiunea în inch, numărul de culori şi rezoluţie. Să se definească funcţiile de setare, de modificare a datelor, de comparare a monitoarelor. Pentru crearea cîmpurilor textuale să se utilizeze operatorul new. Să se elibereze memoria. În main să se exemplifice căutarea monitorului potrivit după dimensiune şi alte
caracteristici.

## Fișiere
- monitor.h 

   Header file responsabil pentru definirea structurile monitor și oferind prototipurile funcțiilor necesare pentru manipularea și interogarea acesteia.
- monitor.cpp

   Conține implementarea funcțiilor definite în monitor.h

- main.cpp

   Fișierul central ce permite operarea cu structura monitor. Utilizează un menu care include fiecare opțiune disponibilă.


## Instrucțiuni de compilare
Proiectul poate fi compilat și executat folosind două metode: direct prin compilatorul g++ sau prin utilizarea CMake.

 - Compilare Directă cu g++

   1. Deschideți un terminal în directorul proiectului.
   2. Rulați comanda de compilare: ```g++ main.cpp monitor.cpp -o main.exe```
   3. După compilare, executați programul cu: ```./main.exe```

 - Compilare cu CMake
