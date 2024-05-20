#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdint.h>


//--------------//
// instructions //
//--------------//

// Register instructions
#define SET     0
#define MOV     1

// Stack instructions
#define PUSH    2
#define POP     3
#define LOAD    4
#define SETVAR  5

// Change instruction pointer instruction 
#define JUMP    6
#define CJUMP   

// Arithmetic instructions
#define ADD     7
#define SUB     8
#define MUL     9
#define DIV     10
#define MOD     11
#define LSHIFT  12
#define RSHIFT  13

// Bit logic instructions
#define GRT     14
#define LST     15
#define OR      16
#define AND     17
#define XOR     18
#define NOT     21

// Byte logic instructions
#define LAND    23
#define LOR     24
#define EQ      25
#define NEQ     26

// Mutex instructions
#define GET_MUTEX  28
#define FREE_MUTEX 29
#define HAS_MUTEX  30

// IO instructions
#define WRITE_IO    31
#define READ_IO     32
// stdOut = 0
// stdIn  = 1
// 
// 

#define OUTPUT_IO   33
#define INPUT_IO    34

#define TO_STDO     35
#define FROM_STDI   36

// Program end instruction
#define END_PROG    37


//-----------//
// Registers //
//-----------//
#define REG0    0
#define REG1    1
#define REG2    2
#define REG3    3
#define REG4    4
#define REG5    5
#define REG6    6
#define REG7    7
#define REG8    8
#define REG9    9
#define REG10   10
#define REG11   11
#define REG12   12
#define REG13   13
#define REG14   14
#define REG15   15
#define REG16   16
#define REG17   17
#define REG18   18
#define REG19   19
#define REG20   20
#define REG21   21

// Extra register information 
#define NUM_REGS    22
#define RET_REG     0

//---------------------------------//
// Number of bytes per instruction //
//---------------------------------//
#define INSTR_SIZE 4

class Interpreter {
    private:
        uint8_t *programStart;
        uint8_t *programPointer;

        // Initialise the registers
        uint8_t registers[NUM_REGS];

                // Register functions
        void set(uint8_t reg, uint8_t value);
        void mov(uint8_t regFrom, uint8_t regTo);

        // Change instruction pointer
        void jump(void);

        // Arithmetic functions
        void add(void);
        void sub(void);
        void mul(void);
        void divIns(void);
        void mod(void);
        void lshift(void);
        void rshift(void);

        // Bit logic functions
        void bitOr(void);
        void bitAnd(void);
        void bitXor(void);
        void bitNor(void);
        void bitNand(void);
        void bitNot(void);
        void bitXnor(void);

        // Byte logic functions
        void logicAnd(void);
        void logicOr(void);
        void grt(void);
        void lst(void);
        void logicEq(void);
        void logicNeq(void);
        void logicNot(void);

        // Mutex functions
        void getMutex(void);
        void freeMutex(void);
        void hasMutex(void);

        // IO operation functions
        void writeIo(void);
        void readIo(void);
        void outputIo(void);
        void inputIo(void);
        void toStdo(void);
        void fromStdi(void);

        // End the program
        void endProg();

    public:
        Interpreter(uint8_t *program);
        ~Interpreter();

        void* run(void);
        static void *runHelper(void *interpreter);

        uint8_t executeInstruction(uint8_t *instruction);
};


#endif // INTERPRETER_H