#ifndef PROCESS_H
#define PROCESS_H

struct Process {
    int id;            // Process_ID
    int burstTime;
    int arrivalTime;
    int priority;       // for Priority Scheduling
    int remainingTime;  //for Round Robin
    int startTime;      //for SJF
};


#endif

