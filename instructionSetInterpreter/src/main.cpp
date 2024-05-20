#include <stdio.h>
#include <pthread.h>

#include "interpreter/interpreter.hpp"

void* printNumbers(void *arg) {
    for (uint8_t i = 0; i < 5; i++)
        printf("i = %d\n", i);
    
    return NULL;
}

typedef void * (*THREADFUNCPTR)(void *);

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
        ADD, REG0, REG1, REG5,
        POP, 0, 0, 0,
        END_PROG, REG5, 0, 0
    };

    uint32_t *program = (uint32_t *)code;

    Interpreter *testInterpreter = new Interpreter((uint32_t*)program);
    // testInterpreter.run()

    // pthread_create(&aThread, NULL, printNumbers, NULL);
    pthread_create(&aThread, NULL, &Interpreter::runHelper, testInterpreter);
    
    pthread_join(aThread, NULL);

    return 0;
}
