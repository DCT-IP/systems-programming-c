/*
FCFS
first come, first serve, simplest type of cpu scheduling algo
a non-preemptive algo until it voluntarily reliquenshes the cpu(typically to termiate or I/O)
priorty not considered

mechanics 
  arrival: processes enter th system and placed in a queue in order of arrival
  execution: cpu takes the first process from the front of the queue.
  repeat: the cpu takes the next process in the queue and repeats the execution process
  process goes on till no more processes left in queue

example 
  1. assume same arrival time 
  process   arrival time    burst time         p1 will run for 5 units of time
    p1           0             5               p2 for next 3 
    p2           0             3               p3 for next 8
    p3           0             8               in total 16 units of time consumed
    so now AT-> arrival time, BT->burst time, TAT -> turn around time, WT -> waiting time 
    TAT = CT - AT
    WT = TAT - BT
    so,
          TAT       WT
    p1    5         0
    p2    8         5
    p3    16        8

  2. diff arrival time
  process    BT    AT
    p1       5     2                           p2 will arrive at t = 0 and run for 3 units, CT = 3
    p2       3     0                           p1 at t = 2, but needs to wait for p2 to finish so t=3 starts making CT = 8
    p3       4     4                           p3 at t=4, but needs to wait for p1 to finish, p3 at t=8 thus CT = 12
    so, 
         CT     TAT     WT
    p1   3       3      0
    p2   8       6      1 
    p3   12      8      4
*/
#include <stdio.h>
#define MAX 5

typedef enum {
  NEW,
  READY,
  RUNNING, 
  DONE //basic states as just a simulation
} state_t;

typedef struct {
  int pid;
  int BT;
  state_t state;
} process_t;

typedef struct {
  process_t  queue[MAX];
  int front, rear, count;
} queue_t;

void initialize(queue_t rq){
  rq.front = 0; rq.rear = 0;rq.count = 0;
}
int is_empty(queue_t rq){
  return rq.count==0;
}
void enque(queue_t rq, process_t p){
  p.state = RUNNING;
  rq.queue[rq.rear] = p;
  rq.rear = (rq.rear+1) % MAX;
  rq.count++;
}
process_t dequeue(queue_t rq){
  process_t ret = rq.queue[rq.front];
  rq.front = (rq.front+1)%MAX;
  rq.count--;
  return ret;
}
void fcfs(){
  //tbd later
}
int main(){
  process_t p1 = {1,5,NEW};
  process_t p2 = {2,3,NEW};
  process_t p3 = {3,8,NEW};

}