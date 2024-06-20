#ifndef RR_H
#define RR_H

#include<bits/stdc++.h>
#include "process.h"

using namespace std;

void rrScheduling(vector<Process> &processes, int timeQuantum){
    int n = processes.size();
    int totalWaitTime = 0;
    int totalTurnaroundTIme = 0;
    int currentTime = 0;
    vector<Process> readyQueue;

    for(auto& process : processes){
        process.remainingTime = process.burstTime;
    }

    while(!processes.empty() || !readyQueue.empty()){
        while(!processes.empty() && processes.front().arrivalTime <= currentTime){
            readyQueue.push_back(processes.front());
            processes.erase(processes.begin());
        }
        if(readyQueue.empty()){
            currentTime++;
            continue;;
        }

        Process currentProcess = readyQueue.front();
        readyQueue.erase(readyQueue.begin());

        int executionTime = min(timeQuantum, currentProcess.remainingTime);
        currentProcess.remainingTime -= executionTime;
        currentTime += executionTime;

        if(currentProcess.remainingTime > 0){
            readyQueue.push_back(currentProcess);
        }
        else{
            int WaitTime = currentTime - currentProcess.arrivalTime - currentProcess.burstTime;
            totalWaitTime += WaitTime;

            int turnaroundTime = currentTime - currentProcess.arrivalTime;
            totalTurnaroundTIme += turnaroundTime;

            result << "Process " << currentProcess.id << ": Wait Time = " << WaitTime << ", TurnAround Time = " << turnaroundTime << endl;
        }
    }

    result << "Average Wait Time = " << (double)totalWaitTime / n << endl;
    result << "Average Turnaround Time = " << (double)totalTurnaroundTIme / n << endl;
}

#endif