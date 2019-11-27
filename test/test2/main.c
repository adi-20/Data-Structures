// An airport is developing a computer simulation of air-traffic control that handles events such as
// landings and takeoffs. Each event has a time stamp that denotes the time when the event will
// occur with additional information like, plane number, takeoff or landing. Design and implement
// suitable data structures that work efficiently in terms of time. Time stamp can be for 00.00 AM
// is considered as 0, 11.30 AM as 1130, 1.30 PM as 1330 and so on.

// Question 1
// 1.Insert an event with a given time stamp, aircraft number, takeoff / landing (add a future
// event).  
// 2.Extract the event with smallest time stamp (that is, determine the next event to process).
// Design and implement suitable data structures that work efficiently in terms of time.
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "heap.h"

void test_sort( Event** data, uint32_t len) 
{
	uint32_t idx;
	for (idx = 1; idx < len; ++idx) {
		assert(data[idx]->timestamp >= data[idx+1]->timestamp);		
	}
}

Event** create_random_flights(){
	Event** data  = (Event**) malloc(6*sizeof(Event*));
	data[1] = (Event*) malloc(sizeof(Event));
	data[1]->timestamp = 200;
	data[1]->plane_no = 123;
	data[1]->t_or_l = TAKEOFF;

	data[2] = (Event*) malloc(sizeof(Event));
	data[2]->timestamp = 100;
	data[2]->plane_no = 124;
	data[2]->t_or_l = LANDING;

	data[3] = (Event*) malloc(sizeof(Event));
	data[3]->timestamp = 550;
	data[3]->plane_no = 134;
	data[3]->t_or_l = LANDING;

	data[4] = (Event*) malloc(sizeof(Event));
	data[4]->timestamp = 50;
	data[4]->plane_no = 234;
	data[4]->t_or_l = TAKEOFF;

	data[5] = (Event*) malloc(sizeof(Event));
	data[5]->timestamp = 0;
	data[5]->plane_no = 12;
	data[5]->t_or_l = LANDING;

	return data;
}
void  print_events(Event** evnts,int length){
	printf("\nHello WOrld\n");
	for(int i =1;i<=length;i++){
		printf("\n%d,%d,%d\n",evnts[i]->timestamp,evnts[i]->plane_no,evnts[i]->t_or_l);
		
	}
}
Event* create_event(int time,int pl_no,int t_l){
	Event* ptr = (Event*) malloc(sizeof(Event));
	ptr->timestamp = time;
	ptr->plane_no = pl_no;
	ptr->t_or_l = t_l;
	return ptr;
}
void test_heap()
{
	Event** evnt = create_random_flights();
	// print_events(evnt,5);
	Heap heap = heap_new(evnt, 5);
	Heap* heap_ptr = &heap;	
	// print_events(heap.data,5);
	Event* ev = heap_get_min(heap_ptr);
	printf("\nEvent:%d\n",ev->timestamp);
	assert(ev->timestamp == 0);
	assert(heap_extract_min(heap_ptr)->timestamp == 0);
	assert(heap_size(heap_ptr) == 4);
	ev = create_event(10,47,LANDING);
	heap_insert(heap_ptr, ev);
	assert(heap_size(heap_ptr) == 5);
	heap_test(heap_ptr);
	
	assert(heap_get_min(heap_ptr)->timestamp == 10);
	assert(heap_extract_min(heap_ptr)->timestamp == 10);
	
	heap_test(heap_ptr);

	
	
	assert(heap_size(heap_ptr) == 4);
	heap_sort(heap_ptr);
	printf("\nHello world is waiting for you!!\n");
	print_events(heap_ptr->data,5);
	test_sort(heap.data, 5);
	printf("\nHello world is waiting for you!!\n");
	Event *elll;
	elll->timestamp=10;
	printf("%d\n",elll->timestamp);
}

int main()
{
	test_heap();
	return 0;
}