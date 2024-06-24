#ifndef SCHEDULER
#define SCHEDULER

#define MAX 10

typedef struct {
    char process_name[20];
    int burst_time;
    int arrival_time;
    int execution_time;
    int waiting_time;
    int total_time;
} Process;

typedef struct {
    Process list[MAX];
    int count;
} ProcessList;

void initProcess(ProcessList *P);
void addProcess(ProcessList *P);

void display(ProcessList P);

#endif