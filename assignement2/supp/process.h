#ifndef _PROCESS_STRUCTURE_
#define _PROCESS_STRUCTURE_
#include <stdint.h>
#include "../../Queue/queue.h"
#include "../../comm.h"

#define FIFO 1
#define SJF 2

typedef struct __process__ Process;
typedef struct __job_scheduler__ Scheduler;
typedef struct __scheduler_result__ SchedulerResult;

struct __process__{
    int32_t pid;
    uint32_t a_time;// arrival time
    uint32_t e_time;// execution time
    uint32_t s_time; //service time
    uint16_t complete;
};

struct __job_scheduler__{
    Queue* jobs;
    uint32_t wait_time;
    uint32_t total_process;
    uint32_t type; // if fifo or short job first algorithm
};

struct __scheduler_result__{
    uint32_t w_time;
    uint32_t ta_time;
};


Scheduler* createFIFOJobScheduler();
Scheduler* createSJFJobScheduler();
OprResult* addProcess(Scheduler* s,Process* prcs);
SchedulerResult* getResult(Scheduler* schdlr);


Process* createProcess(int32_t pid,uint32_t arrival_time, uint32_t execution_time);

#endif