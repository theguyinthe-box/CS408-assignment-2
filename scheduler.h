#ifndef SCHEDULER_H
#define SCHEDULER_H

#include<vector>
#include "log.h"
#include "process.h"

using namespace std;

struct SharedData {
    double alpha;
    bool waiting;
};

// TODO write struct to hold scheduler data structure
struct Scheduler {
    //vector<Process> ready;
    //vector<Process> blocked;
    //Scheduler(SharedData shareInput) ready(shareInput.processes()) {}
};


#endif