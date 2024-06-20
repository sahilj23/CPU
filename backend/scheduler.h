#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <bits/stdc++.h>
#include "process.h"
#include "fcfs.h"
#include "sjf.h"
#include "priority.h"
#include "rr.h"

using namespace std;

vector<Process> InputProcesses(const vector<Process>& inputProcesses) {
    vector<Process> processes = inputProcesses;
    return processes;
}

string runScheduler(const string& algorithm, const vector<Process>& inputProcesses, int timeQuantum = 0) {
    vector<Process> processes = InputProcesses(inputProcesses);
    stringstream result;

    if (algorithm == "FCFS") {
        fcfsScheduling(processes, result);
    } else if (algorithm == "SJF") {
        sjfScheduling(processes, result);
    } else if (algorithm == "RR") {
        rrScheduling(processes, timeQuantum, result);
    } else if (algorithm == "Priority") {
        priorityScheduling(processes, result);
    } else {
        result << "INVALID CHOICE!" << endl;
    }

    return result.str();
}

#endif
