#include <stdio.h>
#include <string.h>
#include "scheduler.h"

void initProcess(ProcessList *P){
    P->count = 0;
}

void calculateProcess(ProcessList *P){
    
}

void addProcess(ProcessList *P){
    size_t len;


    if(P->count != MAX){    
        // Name of process
        printf("Please enter the process name: ");
        if (fgets(P->list[P->count].process_name, MAX, stdin) != NULL) {
            len = strlen(P->list[P->count].process_name);
            if (len > 0 && P->list[P->count].process_name[len - 1] == '\n') {
                P->list[P->count].process_name[len - 1] = '\0';
            }
        } else {
            printf("Error reading process name.\n");
        }

        // burst and arrival time
        printf("\nEnter the burst time: ");
        scanf(" %d",&P->list[P->count].burst_time);

        printf("\nEnter the arrival time: ");
        scanf(" %d",&P->list[P->count].arrival_time);



        //increase count
        P->count++;
    } else {
        printf("\nProcess is Full");
    }
}

void sortFCFS(ProcessList *P) {
    Process tmp;
    int ndx, jdx;

    if(P == NULL) {
        printf("\nEmpty Process List");
    } else {
        for(ndx = 0; ndx < P->count - 1; ndx++) {
            for(jdx = 0; jdx < P->count - ndx - 1; jdx++) {
                if(P->list[jdx].arrival_time > P->list[jdx + 1].arrival_time) {
                    // Swap the processes
                    tmp = P->list[jdx];
                    P->list[jdx] = P->list[jdx + 1];
                    P->list[jdx + 1] = tmp;
                }
            }
        }
    }
}

void display(ProcessList P){
    int ndx;

    printf("\n%12s |%11s | %12s |%15s |%13s | %15s\n", "Process Name", "Burst Time", "Arrival Time", "Execution Time", "Waiting Time", "Turnaround Time");
    
    for(ndx = 0; P.count != 0 && ndx < P.count ; ndx++){
        printf("%12s |", P.list[ndx].process_name);
        printf("%11d |", P.list[ndx].burst_time);
        printf(" %12d |", P.list[ndx].arrival_time);
    }
}