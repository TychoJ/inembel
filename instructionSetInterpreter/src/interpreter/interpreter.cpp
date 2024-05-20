#include <stdint.h>
#include <stdlib.h>

#include "interpreter.hpp"


Interpreter::Interpreter(uint32_t *program) {
    this->programStart = program;
    this->instructionPointer = program;
}

Interpreter::~Interpreter() {
}

void *Interpreter::runHelper(void *interpreter) {
    return ((Interpreter *)interpreter)->run();
}

void* Interpreter::run(void) {
    while(1) {
        this->opcode  = *this->instructionPointer >> 0  & 0xff;
        this->option1 = *this->instructionPointer >> 8  & 0xff;
        this->option2 = *this->instructionPointer >> 16 & 0xff;
        this->option3 = *this->instructionPointer >> 24 & 0xff;

        this->executeInstruction(this->instructionPointer);
        this->instructionPointer += 1;
    }
}

void Interpreter::executeInstruction(uint32_t *instruction) {
    switch (this->opcode)
    {
    case SET:
        this->set(this->option1, this->option2);
        break;
    case MOV:
        this->mov(this->option1, this->option2);
        break;

    case PUSH:
        this->push();
        break;
    case POP:
        this->pop();
        break;
    case LOAD:
        this->load();
        break;
    case STORE:
        this->store();
        break;

    case JUMP:
        this->jump();
        break;
    
    case ADD:
        this->add();
        break;
    case SUB:
        this->sub();
        break;
    case MUL:
        this->mul();
        break;
    case DIV:
        this->divIns();
        break;
    case MOD:
        this->mod();
        break;
    case LSHIFT:
        this->lshift();
        break;
    case RSHIFT:
        this->rshift();
        break;

    case GRT:
        this->grt();
        break;
    case LST:
        this->lst();
        break;
    case AND:
        this->bitAnd();
        break;
    case OR:
        this->bitOr();
        break;
    case XOR:
        this->bitXor();
        break;
    case NOT:
        this->bitNot();
        break;

    case LAND:
        this->logicAnd();
        break;
    case LOR:
        this->logicOr();
        break;
    case EQ: 
        this->logicEq();
        break;
    
    case WRITE:
        break;
    case READ:
        break;
    
    case INSP:
        break;

    case END_PROG:
        this->endProg();
        break;    

    default:
        this->registers[REG1] = 0xff;
        this->option1 = REG1;
        this->endProg();
        break;
    }
    return;
}

//--------------------//
// Register functions //
//--------------------//
void Interpreter::set(uint32_t reg, uint32_t value) {
    this->registers[reg] = value;
    return;
}

void Interpreter::mov(uint32_t regFrom, uint32_t regTo) {
    this->registers[regTo] = this->registers[regFrom];
    return;
}

//-----------------//
// Stack functions //
//-----------------//
void Interpreter::push(void) {
    if (this->stackPointer == STACK_SIZE) {
        this->registers[REG1] = 0xfe;
        this->option1 = REG1;
        this->endProg();
    }

    this->stack[stackPointer] = this->registers[this->option1];
    this->stackPointer++;

    

    return;
}

void Interpreter::pop(void) {
    if (this->stackPointer == 0) {
        this->registers[REG1] = 0xfd;
        this->option1 = REG1;
        this->endProg();
    }

    this->stackPointer--;

    return;
}

void Interpreter::load(void) {
    if (this->registers[this->option1] >= this->stackPointer) {
        this->registers[REG1] = 0xfc;
        this->option1 = REG1;
        this->endProg();
    }

    this->registers[this->option2] = this->stack[this->registers[this->option1]];

    return;
}

void Interpreter::store(void) {
    if (this->registers[this->option1] >= this->stackPointer) {
        this->registers[REG1] = 0xfc;
        this->option1 = REG1;
        this->endProg();
    }

    this->stack[this->registers[this->option1]] = this->registers[this->option2];

    return;
}


//----------------------------//
// Change instruction pointer //
//----------------------------//
void Interpreter::jump(void) {
    *this->instructionPointer = registers[this->option1];
    return;
}

void Interpreter::cjump(void) {
    if (registers[this->option1])
        *this->instructionPointer = registers[this->option2];
    return;
}

//----------------------//
// Arithmetic functions //
//----------------------//
void Interpreter::add(void) {
    this->registers[this->option3] = this->registers[this->option1] + this->registers[this->option2];
    return;
}

void Interpreter::sub(void) {
    this->registers[this->option3] = this->registers[this->option1] - this->registers[this->option2];
    return;
}

void Interpreter::mul(void) {
    this->registers[this->option3] = this->registers[this->option1] * this->registers[this->option2];
    return;
}

void Interpreter::divIns(void) {
    this->registers[this->option3] = this->registers[this->option1] / this->registers[this->option2];
    return;
}

void Interpreter::mod(void) {
    this->registers[this->option3] = this->registers[this->option1] % this->registers[this->option2];
    return;
}

void Interpreter::lshift(void) {
    this->registers[this->option3] = this->registers[this->option1] << this->registers[this->option2];
    return;
}

void Interpreter::rshift(void) {
    this->registers[this->option3] = this->registers[this->option1] >> this->registers[this->option2];
    return;
}

//---------------------//
// Bit logic functions //
//---------------------//
void Interpreter::bitOr(void) {
    this->registers[this->option3] = this->registers[this->option1] | this->registers[this->option2];
    return;
}

void Interpreter::bitAnd(void) {
    this->registers[this->option3] = this->registers[this->option1] & this->registers[this->option2];
    return;
}

void Interpreter::bitXor(void) {
    this->registers[this->option3] = this->registers[this->option1] ^ this->registers[this->option2];
    return;
}

void Interpreter::bitNot(void) {
    this->registers[this->option2] = ~this->registers[this->option1];
    return;
}

//----------------------//
// Byte logic functions //
//----------------------//
void Interpreter::grt(void) {
    this->registers[this->option3] = this->registers[this->option1] > this->registers[this->option2];
    return;
}

void Interpreter::lst(void) {
    this->registers[this->option3] = this->registers[this->option1] < this->registers[this->option2];
    return;
}

void Interpreter::logicAnd(void) {
    this->registers[this->option3] = this->registers[this->option1] && this->registers[this->option2];
    return;
}

void Interpreter::logicOr(void) {
    this->registers[this->option3] = this->registers[this->option1] || this->registers[this->option2];
    return;
}

void Interpreter::logicEq(void) {
    this->registers[this->option3] = this->registers[this->option1] == this->registers[this->option2];
    return;
}

//------------------------//
// IO operation functions //
//------------------------//
void Interpreter::write(void) {
    return;
}

void Interpreter::read(void) {
    return;
}

//-----------------//
// End the program //
//-----------------//
void Interpreter::endProg(void) {
    // TODO implement: free all vars

    exit(this->registers[this->option1]);
}