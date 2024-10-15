#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <pthread.h>
#include<vector>
#include <algorithm>
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
    vector<Process> blocked;
    vector<Process> complete;

    Scheduler(vector<Process> ready) : ready(ready) {}
};

vector<Process> getProcesses(SharedData* shared_data) {
    return shared_data->processes;
}

void* schedulerMain(void* inheritance) {
    Scheduler scheduler(getProcesses((SharedData*)inheritance));

    pthread_exit(0);
}

#endif