#ifndef _PROCESS_STRUCTURE_
#define _PROCESS_STRUCTURE_
#include <stdint.h>

typedef struct __process__ Process;

struct __process__{
    int32_t pid;
    uint32_t a_time;// arrival time
    uint32_t e_time;// execution time
    uint32_t w_time; //wait time
};

Process createProcess(int32_t pid, uint32_t execution){
    Process* p = (Process*) malloc(sizeof(Process));
    p->pid = pid;
    p->e_time = execution;
    p->a_time = 0;
    p->w_time = 0;
    return *p;
}

#endif