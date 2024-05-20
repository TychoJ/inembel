#include <stdint.h>
#include <stdlib.h>

#include "interpreter.hpp"


Interpreter::Interpreter(uint8_t *program) {
    this->programStart = program;
    this->programPointer = program;
}

Interpreter::~Interpreter() {
}

void* Interpreter::run(void) {
    while(1) {
        this->executeInstruction(this->programPointer);
        this->programPointer += INSTR_SIZE;
    }
}

void *Interpreter::runHelper(void *interpreter) {
    return ((Interpreter *)interpreter)->run();
}

uint8_t Interpreter::executeInstruction(uint8_t *instruction) {
    switch (instruction[0])
    {
    case SET:
        this->set(instruction[1], instruction[2]);
        break;
    case END_PROG:
        this->endProg();
        break;
    case MOV:
        this->mov(instruction[1], instruction[2]);
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
    case NOR:
        this->bitNor();
        break;
    case NAND:
        this->bitNand();
        break;
    case NOT:
        this->bitNot();
        break;
    case XNOR:
        this->bitXnor();
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
    case NEQ:
        this->logicNeq();
        break;
    case LNOT:
        this->logicNot();
        break;
    

    default:
        this->registers[REG1] = 0xff;
        this->endProg();
        break;
    }
    return 0;
}

//--------------------//
// Register functions //
//--------------------//
void Interpreter::set(uint8_t reg, uint8_t value) {
    this->registers[reg] = value;
    return;
}

void Interpreter::mov(uint8_t regFrom, uint8_t regTo) {
    this->registers[regTo] = this->registers[regFrom];
    return;
}

//----------------------------//
// Change instruction pointer //
//----------------------------//
void Interpreter::jump(void) {
    this->programPointer = REG0;
    return;
}

//----------------------//
// Arithmetic functions //
//----------------------//
void Interpreter::add(void) {
    this->registers[RET_REG] = this->registers[REG0] + this->registers[REG1];
    return;
}

void Interpreter::sub(void) {
    this->registers[RET_REG] = this->registers[REG0] - this->registers[REG1];
    return;
}

void Interpreter::mul(void) {
    this->registers[RET_REG] = this->registers[REG0] * this->registers[REG1];
    return;
}

void Interpreter::divIns(void) {
    this->registers[RET_REG] = this->registers[REG0] / this->registers[REG1];
    return;
}

void Interpreter::mod(void) {
    this->registers[RET_REG] = this->registers[REG0] % this->registers[REG1];
    return;
}

void Interpreter::lshift(void) {
    this->registers[RET_REG] = this->registers[REG0] << this->registers[REG1];
    return;
}

void Interpreter::rshift(void) {
    this->registers[RET_REG] = this->registers[REG0] >> this->registers[REG1];
    return;
}

//---------------------//
// Bit logic functions //
//---------------------//
void Interpreter::grt(void) {
    this->registers[RET_REG] = this->registers[REG0] > this->registers[REG1];
    return;
}

void Interpreter::lst(void) {
    this->registers[RET_REG] = this->registers[REG0] < this->registers[REG1];
    return;
}

void Interpreter::bitOr(void) {
    this->registers[RET_REG] = this->registers[REG0] | this->registers[REG1];
    return;
}

void Interpreter::bitAnd(void) {
    this->registers[RET_REG] = this->registers[REG0] & this->registers[REG1];
    return;
}

void Interpreter::bitXor(void) {
    this->registers[RET_REG] = this->registers[REG0] ^ this->registers[REG1];
    return;
}

void Interpreter::bitNor(void) {
    this->registers[RET_REG] = ~(this->registers[REG0] | this->registers[REG1]);
    return;
}

void Interpreter::bitNand(void) {
    this->registers[RET_REG] = ~(this->registers[REG0] & this->registers[REG1]);
    return;
}

void Interpreter::bitNot(void) {
    this->registers[RET_REG] = ~this->registers[REG0];
    return;
}

void Interpreter::bitXnor(void) {
    this->registers[RET_REG] = ~(this->registers[REG0] ^ this->registers[REG1]);
    return;
}

//----------------------//
// Byte logic functions //
//----------------------//
void Interpreter::logicAnd(void) {
    this->registers[RET_REG] = this->registers[REG0] && this->registers[REG1];
    return;
}

void Interpreter::logicOr(void) {
    this->registers[RET_REG] = this->registers[REG0] || this->registers[REG1];
    return;
}

void Interpreter::logicEq(void) {
    this->registers[RET_REG] = this->registers[REG0] == this->registers[REG1];
    return;
}

void Interpreter::logicNeq(void) {
    this->registers[RET_REG] = this->registers[REG0] != this->registers[REG1];
    return;
}

void Interpreter::logicNot(void) {
    this->registers[RET_REG] = !this->registers[REG0];
    return;
}

//-----------------//
// Mutex functions //
//-----------------//
void Interpreter::getMutex(void) {
    return;
}

void Interpreter::freeMutex(void) {
    return;
}

void Interpreter::hasMutex(void) {
    return;
}

//------------------------//
// IO operation functions //
//------------------------//
void Interpreter::writeIo(void) {
    return;
}

void Interpreter::readIo(void) {
    return;
}

void Interpreter::outputIo(void) {
    return;
}

void Interpreter::inputIo(void) {
    return;
}


void Interpreter::toStdo(void) {
    return;
}

void Interpreter::fromStdi(void) {
    return;
}

//-----------------//
// End the program //
//-----------------//
void Interpreter::endProg(void) {
    // TODO implement: free all vars

    exit(this->registers[REG0]);
}