#ifndef PROCESS_H
#define PROCESS_H

#include "log.h"

using namespace std;

//TODO write struct to hold process data structure
struct Process {
    unsigned int procID,
                 cpuExecutedTime,
                 ioExecutedTime,
                 totalElapsedTime;
    ExecutionStopReasonType stopReason;
};


#endif