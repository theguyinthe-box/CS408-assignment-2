#ifndef SCHEDULER_H
#define SCHEDULER_H

#include<vector>
#include "log.h"
#include "process.h"

using namespace std;

struct SharedData {
    vector<Process> allBursts;
    double alpha;
    bool waiting;
    SharedData(double a) alpha(a) {}
};

// TODO write struct to hold scheduler data structure
struct Scheduler {
    SharedData* data;

    //vector<Process> ready;
    //vector<Process> blocked;
    //vector<Process> complete;
    //Scheduler(SharedData shareInput) ready(shareInput.processes()) {}
};


#endif