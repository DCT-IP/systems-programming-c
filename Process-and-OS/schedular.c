/*
Round Robin, schedular with a single READY queue
this can be extended to 
 - priority scheduling
 - MLFQ(multilevel feedback queue)
 - WAITING queues
FCFS can be used 

data types :-
PCB -> pid, state, remaining_time
states -> NEW, READY, RUNNING, TERIMNATED
a circular array{queue}, will have PCB ptrs, enqueues only READY processes
quantum will be fixed not dynamic as this is a beginner level os
no wall-clock time wil be used 

architecture :-
+-------------------+
|   Ready Queue     |
+-------------------+
        |
     dequeue
        ↓
    RUNNING
        |
   consumes quantum
        ↓
  ┌─────────────┐
  | finished ?  |
  └─────┬───────┘
        | yes          no
        ↓              ↓
  TERMINATED        enqueue back
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#define QUANTUM 2 
/*   Process states      */
typedef enum{
    NEW,
    READY,
    RUNNING,
    TERMINATED
}state_t;  

/*  PCB  */
typedef struct {
    int pid;
    state_t state;
    int remaining_time;
}process_t;

/*    READY queue     */
typedef struct{
    process_t *proc_queue[MAX];       //queue
    int front;
    int rear;
    int count
}R_queue_t;

/*    queue operatons     */
void initialize_q(R_queue_t *r){
    r->front = r->rear = r->count = 0;
}

int is_empty(R_queue_t *r){
    return r->count == 0;
}
void enqueue(R_queue_t *r, process_t *p){
    r->proc_queue[r->rear] = p;
    r->rear = (r->rear + 1) % MAX;
    r->count++;
}
process_t *dequeue(R_queue_t *r){
    process_t *pr = r->proc_queue[r->front];
    r->front = (r->front+1)%MAX;
    r->count--;
    return pr;
}

/*    RoundRobin     */
void Round_robin(R_queue_t *rq) {
    while(!is_empty(rq)){
        process_t *pr = dequeue(rq);
        pr->state = RUNNING;
        int slice = (pr->remaining_time>QUANTUM)?QUANTUM:pr->remaining_time;
        printf("PID %d RUNNING for %d units\n", pr->pid, slice);
        pr->remaining_time -= slice;
        if (pr->remaining_time == 0) {
            pr->state = TERMINATED;
            printf("PID %d TERMINATED\n\n", pr->pid);
        } else {
            pr->state = READY;
            enqueue(rq, pr);
        }
    }
}

/*      main function        */
int main() {
    process_t p1 = {1, NEW, 5};
    process_t p2 = {2, NEW, 3};
    process_t p3 = {3, NEW, 8};

    R_queue_t rq;
    initialize_q(&rq);
    /* Admit processes */
    p1.state = READY; enqueue(&rq, &p1);
    p2.state = READY; enqueue(&rq, &p2);
    p3.state = READY; enqueue(&rq, &p3);
    Round_robin(&rq);
    return 0;
}
