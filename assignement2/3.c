/*
    Design a queue to which stores process details like process id, arrival time, execution time and
    priority. Determine the turn-around time and waiting time for each jobs for following scheduling
    algorithms.
    a. First Come First Serve
    b. Shortest Job First

    To Compile : gcc supp/process.c ../Queue/queue.c 3.c 
*/
#include <stdio.h>
#include <assert.h>
#include "supp/process.h"
// #define DATA_TYPE_USED Process
void checkCreateFifo(){
    Scheduler* s = createFIFOJobScheduler();
    assert(s->jobs->length==0);
    assert(s->wait_time==0);
    assert(s->type == FIFO);
    assert(s->total_process==0);
}

void checkCreateSJF(){
    Scheduler* s = createSJFJobScheduler();
    assert(s->jobs->length==0);
    assert(s->wait_time==0);
    assert(s->type != FIFO);
    assert(s->type == SJF);
    assert(s->total_process==0);
}
void checkAddProcess(){
    Process* p = createProcess(100,0,5);
    Scheduler* s = createFIFOJobScheduler();
    OprResult* res = addProcess(s,p);
    assert(res->status==STATUS_OK);
    assert(s->total_process==1);
    assert(s->jobs->length==1);
    p = createProcess(101,1,3);
    res = addProcess(s,p);
    assert(res->status==STATUS_OK);
    assert(s->total_process==2);
    assert(s->jobs->length==2);
}

void testFifo(){
    Process* p = createProcess(100,0,5);
    Scheduler* s = createFIFOJobScheduler();
    addProcess(s,p);
    SchedulerResult* res = getResult(s);
    assert(res->w_time==0);
    assert(s->total_process==1);
    p = createProcess(101,1,3);
    addProcess(s,p);
    res = getResult(s);
    assert(s->total_process==2);
    assert(res->w_time==4);
    p = createProcess(102,20,3);
    addProcess(s,p);
    res = getResult(s);
    assert(s->total_process==3);
    assert(res->w_time==4);
    
}

void testSJF(){
    Process* p = createProcess(100,0,5);
    Scheduler* s = createSJFJobScheduler();
    addProcess(s,p);
    // SchedulerResult* res = getResult(s);
    
    // assert(res->w_time==0);
    // assert(s->total_process==1);
    p = createProcess(101,1,3);
    addProcess(s,p);
    assert(s->total_process==2);
    // res = getResult(s);
    // printf("\n%d\n",res->w_time);
    // assert(res->w_time==4);
    p = createProcess(102,2,8);
    addProcess(s,p);
    p = createProcess(103,3,6);
    addProcess(s,p);
    SchedulerResult* res = getResult(s);
    assert(s->total_process==4);
    assert(res->w_time==21);
}

int main(int var,char **ch){
    checkCreateFifo();
    checkCreateSJF();
    checkAddProcess();
    testFifo();
    testSJF();
}
