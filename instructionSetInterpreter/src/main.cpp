#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "interpreter/interpreter.hpp"

int main(void) {

    pthread_t aThread;
    
    // get program
    uint8_t code[] = {
        SET, REG0, 10, 0,
        SET, REG1, 5, 0,
        PUSH, REG1, 0, 0,
        SET, REG1, 3, 0,
        MUL, REG0, REG1, REG0,
        SET, REG1, 0, 0,
        LOAD, REG1, 0, 0,
        ADD, REG0, REG1, REG7,
        POP, 0, 0, 0,
        SET, REG0, 'H', 0,
        SET, REG1, 'e', 0,
        SET, REG2, 'l', 0,
        SET, REG3, 'l', 0,
        SET, REG4, 'o', 0,
        SET, REG5, '!', 0,
        SET, REG6, '\n', 0,
        WRITE_IO, STDO_IO, REG0, 0,
        WRITE_IO, STDO_IO, REG1, 0,
        WRITE_IO, STDO_IO, REG2, 0,
        WRITE_IO, STDO_IO, REG3, 0,
        WRITE_IO, STDO_IO, REG4, 0,
        WRITE_IO, STDO_IO, REG5, 0,
        WRITE_IO, STDO_IO, REG6, 0,
        END_PROG, REG7, 0, 0
    };

    uint32_t *program = (uint32_t *)code;

    Interpreter *testInterpreter = new Interpreter((uint32_t*)program);
    pthread_create(&aThread, NULL, &Interpreter::runHelper, testInterpreter);

    // Close reading of stdIn of aThread
    // close((*testInterpreter).stdinIo[PREAD]);

    // // Close writing of stdOut of aThread
    // close((*testInterpreter).stdoutIo[PWRITE]);

    // uint8_t readFromProgram = 0;

    for (uint8_t i = 0; i < 0xfe; i += 2)
        i--;
    
    while ((*testInterpreter).running) {
        // printf("start reading stdout\n");
        while ((*testInterpreter).stdoRI != (*testInterpreter).stdoWI) {
            printf("%c", (*testInterpreter).stdoIO[(*testInterpreter).stdoRI]);
            (*testInterpreter).stdoRI++;
        }        
    }
    

    return 0;
}
