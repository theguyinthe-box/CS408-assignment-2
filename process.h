#ifndef PROCESS_H
#define PROCESS_H

#include <vector>
#include "log.h"


using namespace std;

struct Process{
    vector<unsigned int> bursts;

    unsigned int procID,
                 cpuExecutedTime,
                 ioExecutedTime,
                 totalElapsedTime,
                 prevBurst;

    Process();
    Process(vector<unsigned int> b, unsigned int pid) : bursts(b), procID(pid), cpuExecutedTime(0),
                                                        ioExecutedTime(0), totalElapsedTime(0),
                                                        prevBurst(0) {}
};


inline void incrementCPU(Process* process) {
    process->cpuExecutedTime += process->bursts.front();
    process->totalElapsedTime += process->bursts.front();
}

inline void incrementIO(Process* process, unsigned int burst) {
    process->ioExecutedTime += burst;
    process->totalElapsedTime += burst;
}

inline unsigned int decrementBursts(Process* process, unsigned int burst) {
    if ( (process->bursts.front() - burst) < 0 ) {
        unsigned int result = process->bursts.front();
        process->bursts.front() = 0;
        return result;
    }
    process->bursts.front() -= burst;
    return burst;
}

inline unsigned int getCPUBurstSum(Process* process) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i <= process->bursts.size(); i += 2) {
        sum += process->bursts[i];
    }
    return sum;
}

inline unsigned int getAllBurstSum(Process* process) {
    unsigned int sum = 0;
    for (unsigned int i = 0; i <= process->bursts.size(); i++) {
        sum += process->bursts[i];
    }
    return sum;
}

inline float getBurstAvg(Process* process) {
    return getCPUBurstSum(process) / process->bursts.size();
}

#endif