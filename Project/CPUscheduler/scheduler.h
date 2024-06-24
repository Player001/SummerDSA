#ifndef SCHEDULER
#define SCHEDULER

#define MAX 10

typedef struct {
    char process_name[20];
    int burst_time;
    int arrival_time;
    int execution_time;
    int waiting_time;
    int turnaround_time;
} Process;

typedef struct {
    Process list[MAX];
    int count;
} ProcessList;

void initProcess(ProcessList *P);
void calculateProcess(ProcessList *P);
void addProcess(ProcessList *P);

void sortFCFS(ProcessList *P);
void sortSJF(ProcessList *P);

void display(ProcessList P);

#endif