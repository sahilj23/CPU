#ifndef PRIORITY_H
#define PRIORITY_H

#include<bits/stdc++.h>
#include "process.h"
using namespace std;

struct ComparePriority{
    bool operator()(const Process &a, const Process &b){
        return a.priority>b.priority;
    }
};

void priorityScheduling(vector<Process>& processes){
    int n = processes.size();
    priority_queue<Process, vector<Process>, ComparePriority> pq;
    int totalWaitTime = 0; 
    int totalTurnAroundTime = 0;
    int currentTime = 0;
    int processIndex = 0;

    sort(processes.begin(), processes.end(), [](const Process &a, const Process &b){
        return a.arrivalTime < b.arrivalTime;
    });

    while(!pq.empty() || processIndex < n){
        //push all elements that have arrived by the current time in priority queue
        while(processIndex < n && processes[processIndex].arrivalTime <= currentTime){
            pq.push(processes[processIndex]);
            processIndex++;
        }
        if(!pq.empty()){
            Process currentProcess = pq.top();
            pq.pop();

            int waitTime = currentTime - currentProcess.arrivalTime;
            totalWaitTime += waitTime;

            currentTime += currentProcess.burstTime;

            int turnAroundTime = currentTime - currentProcess.arrivalTime;
            totalTurnAroundTime += turnAroundTime;

            result << "Process " << currentProcess.id << ": Wait Time = " << waitTime << ", Turnaround Time = " << turnAroundTime << endl;
        }
        else{
            // if queue is empty move the current time to the next process's arrival time
            if(processIndex < n){
                currentTime = processes[processIndex].arrivalTime;
            }
        }

    }

//     //push all processes to the priority queue
//     for(const auto& process : processes){
//         pq.push(process);
//     }
    
//     //process all processes based on priority
//     while(!pq.empty()){
//         Process currentProcess = pq.top();
//         pq.pop();
    

//     //if current time is less than arrival time, increment current time
//     if(currentTime < currentProcess.arrivalTime){
//         currentTime = currentProcess.arrivalTime;
//     }

//     int waitTime = currentTime - currentProcess.arrivalTime;
//     totalWaitTime = totalWaitTime + waitTime;

//     currentTime += currentProcess.burstTime;

//     int turnAroundTime = currentTime - currentProcess.arrivalTime;
//     totalTurnAroundTime += turnAroundTime;

//     cout << "PROCESS " << currentProcess.id << ": Wait Time = " << waitTime << ", Turnaround Time = " << turnAroundTime << endl;

//   }

  result << "Average Wait Time = " << (double)totalWaitTime / n << endl;
  result << "Average Turnaround Time = " << (double)totalTurnAroundTime / n << endl; 
}

#endif