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
#define STORE   5

// Change instruction pointer instruction 
#define JUMP    6
#define CJUMP   7

// Arithmetic instructions
#define ADD     8
#define SUB     9
#define MUL     10
#define DIV     11
#define MOD     12
#define LSHIFT  13
#define RSHIFT  14

// Bit logic instructions
#define OR      15
#define AND     16
#define XOR     17
#define NOT     18

// Byte logic instructions
#define GRT     19
#define LST     20
#define LAND    21
#define LOR     22
#define EQ      23

// IO instructions
#define WRITE_IO 24
#define READ_IO  25

#define STDO_IO  0
#define STDI_IO  0

#define STDO_BUF_SIZE 1024
#define STDI_BUF_SIZE 1024

// Store the instruction pointer in a register
#define INSP     26

// Program end instruction
#define END_PROG 27

// Information flags
#define FLAG        28

#define OVERFLOW    0
#define UNDERFLOW   1
#define UNRSTDIN    2

#define NUM_FLAGS   3


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
#define REG22   22
#define REG23   23
#define REG24   24
#define REG25   25
#define REG26   26
#define REG27   27
#define REG28   28
#define REG29   29
#define REG30   30
#define REG31   31

// Extra register information 
#define NUM_REGS    32
#define RET_REG     0

// Number of stack entries 
#define STACK_SIZE 4096

//---------------//
// Communication //
//---------------//
#define PWRITE 1
#define PREAD  0


class Interpreter {
    private:
        // Store program information
        uint32_t *programStart;
        uint32_t *instructionPointer;

        // Store information about an instruction
        uint8_t opcode;
        uint8_t option1;
        uint8_t option2;
        uint8_t option3;

        // Information flags
        uint32_t flags[NUM_FLAGS];

        // Stack
        uint32_t stack[STACK_SIZE];
        uint32_t stackPointer = 0;

        // Initialise the registers
        uint32_t registers[NUM_REGS];

        // Functions to run a program
        void* run(void);
        void executeInstruction(uint32_t *instruction);

        // Register functions
        void set(uint32_t reg, uint32_t value);
        void mov(uint32_t regFrom, uint32_t regTo);

        // Stack functions
        void push(void);
        void pop(void);
        void load(void);
        void store(void);

        // Instruction pointer instructions
        void jump(void);
        void cjump(void);
        void insp(void);

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
        void bitNot(void);

        // Byte logic functions
        void grt(void);
        void lst(void);
        void logicAnd(void);
        void logicOr(void);
        void logicEq(void);

        // IO operation functions
        void writeIo(void);
        void readIo(void);

        // End the program
        void endProg();

    public:
        Interpreter(uint32_t *program);
        ~Interpreter();

        // Function to be able to start the program in a separate thread
        static void *runHelper(void *interpreter);

        // Create communication channels
        int stdoutIo[2];
        int stdinIo[2];

        uint32_t stdoIO[STDO_BUF_SIZE];
        uint32_t stdoWI = 0;
        uint32_t stdoRI = 0;

        uint32_t stdinIO[STDI_BUF_SIZE];
        uint32_t stdinWI = 0;
        uint32_t stdinRI = 0;

        uint8_t running = 1;


};


#endif // INTERPRETER_H