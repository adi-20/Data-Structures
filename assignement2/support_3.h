#ifndef _PROCESS_STRUCTURE_
#define _PROCESS_STRUCTURE_
#include <time.h>


typedef struct __process__ Process;

// Process id ,arrival time, execution time
struct __process__{
    int32_t pid;`
    time_t a_time;
    time_t e_time;
}

#endif