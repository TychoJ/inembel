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
    uint8_t program[] = {
        SET, REG0, 10, 0,
        SET, REG1, 5, 0,
        SUB, 0, 0, 0,
        END_PROG, 0, 0, 0
    };

    Interpreter *testInterpreter = new Interpreter(program);
    // testInterpreter.run()

    // pthread_create(&aThread, NULL, printNumbers, NULL);
    pthread_create(&aThread, NULL, &Interpreter::runHelper, testInterpreter);
    
    pthread_join(aThread, NULL);

    return 0;
}
