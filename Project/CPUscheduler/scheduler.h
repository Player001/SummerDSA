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

// Utility functions
void menu(int val, ProcessList *P);
void menuopt();
void initProcess(ProcessList *P);
void display(ProcessList P);

void addProcess(ProcessList *P);
void calculate(ProcessList *P);
void getExecution(ProcessList *P);
void getWaiting(ProcessList *P);
void getTurnaround(ProcessList *P);

int totalWaiting(ProcessList P);
double averageWaiting(ProcessList P);
int totalTurnaround(ProcessList P);
double averageTurnaround(ProcessList P);

void sortFCFS(ProcessList *P);

#endif