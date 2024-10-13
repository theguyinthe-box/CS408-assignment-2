#ifndef PROCESS_H
#define PROCESS_H

#include <vector>

#include "log.h"
#include "scheduler.h"

using namespace std;

typedef enum {
    RUNNING,
    BLOCKED,
    READY,
} ProcessState;


struct Process {
    vector<unsigned int> bursts;
    unsigned int procID,
                 cpuExecutedTime,
                 ioExecutedTime,
                 totalElapsedTime;

    ExecutionStopReasonType stopReason;
    ProcessState state;

    Process(vector<unsigned int> b, unsigned int pid) : bursts(b), procID(pid), cpuExecutedTime(0),
                                                        ioExecutedTime(0), totalElapsedTime(0),
                                                        state(READY) {}
};

Process processInit(Process, vector<unsigned int>, unsigned int);

void incrementCPU(Process *process) {
    process->cpuExecutedTime += process->bursts.front();
}
void incrementIO(Process *process) {
    process->ioExecutedTime += process->bursts.front();
}

#endif