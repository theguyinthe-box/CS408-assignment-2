#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <pthread.h>
#include<vector>
#include <string>
#include <algorithm>
#include <unistd.h>

#include "log.h"
#include "process.h"

using namespace std;

struct SharedData {
    vector<Process> processes;
    double alpha;
    bool waiting;
    SharedData(double a) : alpha(a), waiting(false) {}
};

// TODO write struct to hold scheduler data structure
struct Scheduler {
    vector<Process> ready;
    vector<Process> blockedIO;
    vector<Process> complete;
    unsigned int totalTime;
    Scheduler(vector<Process> ready) : ready(ready), totalTime(0) {}
};

inline vector<Process> getProcesses(SharedData* shared_data) {
    return shared_data->processes;
}

inline bool compareNextProcesses(Process p1, Process p2) {
    return (p1.bursts.front() > p2.bursts.front());
}

void* schedulerMain(void* input);

#endif