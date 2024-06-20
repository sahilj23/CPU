#ifndef SJF_H
#define SJF_H

#include<bits/stdc++.h>
#include "process.h"

using namespace std;

void sjfScheduling(vector<Process> &processes){
    int n = processes.size();
    vector<Process> remainingProcesses = processes;

    int TotalWaitTime = 0;
    int TotalTurnAroundTime = 0;
    int currentTime = 0;

    while(!remainingProcesses.empty()){
         //Finding the process with shortest burst time to be  processed first
         int shortestIndex = -1;
         int minBurstTime = INT_MAX;

         for(int i = 0; i < remainingProcesses.size(); i++){
            if(remainingProcesses[i].arrivalTime <= currentTime && remainingProcesses[i].burstTime < minBurstTime){
                minBurstTime = remainingProcesses[i].burstTime;
                shortestIndex = i;
            }
         }

         if(shortestIndex == -1){
            currentTime++;
            continue;
         }

         Process currentProcess = remainingProcesses[shortestIndex];
         remainingProcesses.erase(remainingProcesses.begin() + shortestIndex);

         int waitTime = currentTime - currentProcess.arrivalTime;
         TotalWaitTime = TotalWaitTime + waitTime;

         int TurnaroundTime = waitTime + currentProcess.burstTime;
         TotalTurnAroundTime = TotalTurnAroundTime + TurnaroundTime;

         currentTime += currentProcess.burstTime;

         result << "Process " << currentProcess.id << ": Wait Time = " << waitTime << ", Turnaround Time = " << TurnaroundTime << endl;
    }
    result << "Average Wait Time = " << (double)TotalWaitTime / n << endl;
    result << "Average Turnaround Time = " << (double)TotalTurnAroundTime / n << endl;  
}

#endif