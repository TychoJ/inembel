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

## Register instructions / Register instructies
The following instructions allow a value to be placed in an arbitrary register.
| SET  	| rx 	| valh 	| vall 	|
|------	|----	|------	|------	|
- `SET` is the SET instruction.
- `rx` is the register in which the value is going to be placed. x can be 0 - 31.
- `valh` are the higher 8 bits of a sixteen bit value.
- `vall` are the lower 8 bits of a sixteen bit value.

| MOVE 	| rx 	| ry   	| NULL 	|
|------	|----	|------	|------	|
- `MOVE` is the MOVE instruction.
- `rx` is the register from which the value is taken to be stored in ry. x can be 0 - 31
- `ry` is the register in which the value of rx is stored. y can be 0 - 31

---
De volgende instructies kunnen gebruikt worden om waardes in een register te laden.
| SET  	| rx 	| valh 	| vall 	|
|------	|----	|------	|------	|
- `SET` is de SET instructie
- `rx` is het register waarin de waarde wordt opgeslagen. x kan 0 - 31 zijn.
- `valh` zijn de hoogste 8 bits van een 16  bits getal.
- `vall` zijn de laagste 8 bits van een 16  bits getal.

| MOVE 	| rx 	| ry   	| NULL 	|
|------	|----	|------	|------	|
- `MOVE` is de MOVE instructie.
- `rx` is het register waarvan de waarde in ry wordt opgeslagen. x kan 0 - 31 zijn.
- `ry` is het register waarin de waarde van rx wordt opgeslagen. y kan 0 - 31 zijn.

## Stack instructions / Stack instructies

## Program pointer instructions / Programma pointer instructies

## Arithmetic instructions / Rekenkundige instructies

## Logic instructions / Logica instructies

## IO instructions / IO instructies

## Program end instruction / Programma einde istructie
