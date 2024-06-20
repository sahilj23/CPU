#ifndef FCFS_H
#define FCFS_H

#include<bits/stdc++.h>
#include "process.h"

using namespace std;

void fcfsScheduling(vector<Process> &processes){
    int n = processes.size();
    int totalWaitTime = 0;
    int totalTurnAroundTime = 0;
    int currTime = 0; 

    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b){
        return a.arrivalTime < b.arrivalTime;
    });

    for(int i = 0; i < n; i++){

        //curr time > arrival time, process has to wait, if not, wait time = 0, so, took max with 0.
        int waitTime = max(0, currTime - processes[i].arrivalTime);
        totalWaitTime = totalWaitTime + waitTime;

        //turnaroundtime = sum of wait time and burst time
        int turnAroundTime = waitTime + processes[i].burstTime;
        totalTurnAroundTime = totalTurnAroundTime + turnAroundTime;

        //end of process execution
        currTime = max(currTime, processes[i].arrivalTime) + processes[i].burstTime;

        result << "Process " << processes[i].id << ": Wait Time = " << waitTime << ", TurnAround Time = " << turnAroundTime << endl;

    }

    result << "Average Wait Time = " << (double)totalWaitTime/n << endl;
    result << "Average TurnAround Time = " << (double)totalTurnAroundTime/n << endl;

}




#endif