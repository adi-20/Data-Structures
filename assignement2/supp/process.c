#include<stdlib.h>
#include<stdio.h>
#include "process.h"

Process* createProcess(int32_t pid,uint32_t arrival_time, uint32_t execution_time){
    Process* p = (Process*) malloc(sizeof(Process));
    p->pid = pid;
    p->e_time = execution_time;
    p->a_time = arrival_time;
    p->s_time = 0;
    p->complete =0;
    return p;
}

Scheduler* createFIFOJobScheduler(){
    Scheduler* s = (Scheduler*) malloc(sizeof(Scheduler));
    s->jobs = create_queue();
    s->wait_time =0;
    s->total_process=0;
    s->type = FIFO;
    return s;
}
Scheduler* createSJFJobScheduler(){
    Scheduler* s = (Scheduler*) malloc(sizeof(Scheduler));
    s->jobs = create_queue();
    s->wait_time =0;
    s->total_process=0;
    s->type = SJF;
    return s;
}

OprResult* addProcess(Scheduler* shdlr,Process* prcs){
    OprResult* res = add(shdlr->jobs,prcs);
    shdlr->total_process++;
    return res;

}


SchedulerResult* createSchdlRes(){
    SchedulerResult* res = (SchedulerResult*) malloc(sizeof(SchedulerResult));
    return res;
}

SchedulerResult* getTotalTime(Scheduler* schdlr){
    SchedulerResult* res = createSchdlRes();
    for(int i = 0;i<schdlr->total_process;i++){
        Process* p = delete(schdlr->jobs)->data;
        add(schdlr->jobs,p);
        res->w_time += (p->s_time - p->a_time);
    }
    res->ta_time = res->w_time;
    return res;
}

Process* getSJFJob(Scheduler* schdlr){

        Process* currProcess = NULL;
        for(int i = 0;i<schdlr->total_process;i++){
            Process* p = delete(schdlr->jobs)->data;
            add(schdlr->jobs,p);
            if(p->complete == 0 && currProcess==NULL ){
                currProcess = p;
            }else if(p->complete == 0 && p->a_time <= schdlr->wait_time && currProcess->e_time > p->e_time ){
                currProcess = p;
            }
        }
        return currProcess;

}
void clearProcessTimes(Scheduler* schdlr){
    schdlr->wait_time = 0;
    for(int i = 0;i<schdlr->total_process;i++){
        Process* p = delete(schdlr->jobs)->data;
        add(schdlr->jobs,p);
        p->complete=0;
        p->s_time = 0;
    }
}
SchedulerResult* getResult(Scheduler* schdlr){
    Process* p =NULL;
    clearProcessTimes(schdlr);
    if(schdlr->type==FIFO){
        for(int i = 0;i<schdlr->total_process;i++){
            Process* p = delete(schdlr->jobs)->data;
            add(schdlr->jobs,p);
            if(p->a_time > schdlr->wait_time){
                schdlr->wait_time = p->a_time;
            }
            p->s_time = schdlr->wait_time;
            schdlr->wait_time += p->e_time;
            p->complete=1;
        }
        
    }else{
        for(int i = 0;i<schdlr->total_process;i++) {
            Process* p = getSJFJob(schdlr);
            if(p->a_time > schdlr->wait_time){
                schdlr->wait_time = p->a_time;
            }
            p->s_time = schdlr->wait_time;
            schdlr->wait_time += p->e_time;
            p->complete=1;
        }
    }
    return getTotalTime(schdlr);
}