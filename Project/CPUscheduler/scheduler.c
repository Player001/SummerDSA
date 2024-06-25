#include <stdio.h>
#include <string.h>
#include "scheduler.h"

void menu(int val, ProcessList *P){
    initProcess(P);
    while(val != 0){
        menuopt();
        scanf(" %d", &val);

        if(val == 1){
            addProcess(P);
        } else if(val == 2){
            calculate(P);
            display(*P);
        } else if (val == 0) {
            val = 0;
        } else {
            printf("\nInvalid Input\n");
        }
    }
}

void menuopt(){
    printf("\nPlease select an option");
    printf("\n===========================================");
    printf("\n1 Add Process");
    printf("\n2 Calculate and Display Processes");
    printf("\n0 Exit\n\n");
}

void initProcess(ProcessList *P){
    P->count = 0;
}

void getExecution(ProcessList *P){
    int ndx;

    for(ndx = 0 ; ndx < P->count ; ndx++){
        if(ndx == 0){
            P->list[ndx].execution_time = 0;
        } else {
            P->list[ndx].execution_time = P->list[ndx-1].execution_time + P->list[ndx-1].burst_time;
        }
    }
}

void getWaiting(ProcessList *P){
    int ndx;

    for(ndx = 0 ; ndx < P->count ; ndx++){
        P->list[ndx].waiting_time = P->list[ndx].execution_time - P->list[ndx].arrival_time;
    }
}

void getTurnaround(ProcessList *P){
    int ndx;

    for(ndx = 0 ; ndx < P->count ; ndx++){
        if(ndx == 0){
            P->list[ndx].turnaround_time = P->list[ndx].burst_time;
        } else {
            P->list[ndx].turnaround_time = P->list[ndx-1].turnaround_time + P->list[ndx].burst_time;
        }
    }
}

void addProcess(ProcessList *P){

    if(P->count != MAX){    
        // Name of process
        printf("Please enter the process name: ");
        scanf(" %20[^\n]", P->list[P->count].process_name);

        // burst and arrival time
        printf("\nEnter the burst time: ");
        scanf(" %d",&P->list[P->count].burst_time);

        printf("\nEnter the arrival time: ");
        scanf(" %d",&P->list[P->count].arrival_time);
       
        //increase count
        P->count++;
        sortFCFS(P);
    } else {
        printf("\nProcess is Full");
    }
}

void calculate(ProcessList *P){
    getExecution(P);
    getWaiting(P);
    getTurnaround(P);
}

int totalWaiting(ProcessList P){
    int ndx;
    int val = 0;

    for(ndx = 0 ; ndx < P.count ; ndx++){
        val = val + P.list[ndx].waiting_time;
    }

    return val;
}

double averageWaiting(ProcessList P){
    double val;

    val = (double)totalWaiting(P)/P.count;

    return val;
}

int totalTurnaround(ProcessList P){
    int ndx;
    int val = 0;

    for(ndx = 0 ; ndx < P.count ; ndx++){
        val = val + P.list[ndx].turnaround_time;
    }

    return val;
}

double averageTurnaround(ProcessList P){
    double val;

    val = (double)totalTurnaround(P)/P.count;

    return val;
}

void sortFCFS(ProcessList *P) {
    Process tmp;
    int ndx, jdx;

    if(P == NULL) {
        printf("\nEmpty Process List");
    } else {
        for(ndx = 0; ndx < P->count - 1; ndx++) {
            for(jdx = 0; jdx < P->count - ndx - 1; jdx++) {
                if(P->list[jdx].arrival_time > P->list[jdx + 1].arrival_time ||
                   (P->list[jdx].arrival_time == P->list[jdx + 1].arrival_time && 
                    P->list[jdx].burst_time > P->list[jdx + 1].burst_time)) {
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

    if(P.count == 0){
        printf("List is empty");
    } else{
        printf("\n%12s |%11s | %12s |%15s |%13s | %15s\n", "Process Name", "Burst Time", "Arrival Time", "Execution Time", "Waiting Time", "Turnaround Time");
        
        for(ndx = 0; P.count != 0 && ndx < P.count ; ndx++){
            printf("%12s |", P.list[ndx].process_name);
            printf("%11d |", P.list[ndx].burst_time);
            printf(" %12d |", P.list[ndx].arrival_time);
            printf("%15d |", P.list[ndx].execution_time);
            printf("%13d |", P.list[ndx].waiting_time);
            printf(" %15d\n", P.list[ndx].turnaround_time);
        }

        printf("Total WT: %d", totalWaiting(P));
        printf("\nAverage WT: %.2f", averageWaiting(P));
        printf("\nTotal TT: %d", totalTurnaround(P));
        printf("\nAverage TT: %.2f", averageTurnaround(P));
    }
}