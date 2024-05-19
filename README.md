# inembel
Inembel stands for instruction set embedded electrical engineering. The goal of this project is to write an instruction set with an assembly compiler. 

---
Inimbel staat voor instructie set embedded elektrotechniek. Het doel van dit project is het schrijven van een instructie set met een daarbij hoorende assembly compiler.

## Goals
The goal of this project is to write a instruction set with interpreter that can be used to collect the credits of the course embedded of the Amsterdam University of Applied Sciences. The requirements of the course embedded systems are:
- Have a custom programming language
- Be able to toggle IO of a raspberry pi
- Read input of raspberry pi pins
- Have a semi OS that can run multiple programs at once
- Have the semi OS control to which program the input of the console goes to

---
Het doel van dit project is het schrijven van een instructie set met een interpreter die gebruikt kan worden voor het vak embedded van de Hogeschool van Amsterdam. De eisen van het vak embedded zijn:
- Het hebben van een eigen programmeer taal
- IO van de raspberry pi hoog en laag kunnen maken
- IO van de raspberry pi kunnen uitlezen
- Het hebben van een semi OS die meerdere programma's tegelijkertijd kan draaien
- De semi OS moet kunnen bepalen naar welk programma de input van de terminal toegaat


# Instructions
In the next couple of subsections the instructions of inembel will be discussed.

Each instruction has 32 bits. The first 8 bits determine the type of instruction. For example if the instruction is an addition, subtraction or something else. Instructions can change the values of the 32 registers that are available. All the 32 registers are 32 bits.

---
In de volgende paragrafen zullen de instructies van inembel worden besproken.  

Elke instructie van inembel bestaat uit 32 bits. De eerste 8 bits bepalen de soort instructie. Bijvoorbeeld of het een optel, vermenigvuldig of andere instructie is. Instructies kunnen de waardes van de 32 registers aanpassen. Alle registers zijn 32 bits.

## Arithmetic instructions / Rekenkundige instructies

## Logic instructions / Logica instructies

