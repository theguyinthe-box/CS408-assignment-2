#include "scheduler.h"

using namespace std;

void* schedulerMain(void* input) {
    SharedData* shared_data = (SharedData*) input;
    Scheduler scheduler(getProcesses(shared_data));


    if(!shared_data->alpha) {
        for(unsigned int i = 0; i < scheduler.ready.size(); i++) {

            //to log the bursts, need to translate from vector to an unsigned int*
            unsigned int bursts[scheduler.ready[i].bursts.size()];

            for(unsigned int j = 0; j < scheduler.ready[i].bursts.size(); j++) {
                bursts[j] = scheduler.ready[i].bursts[j];
            }
            log_process_bursts(scheduler.ready[i].procID,
                               bursts,
                               scheduler.ready[i].bursts.size());
        }
    }

    stable_sort(scheduler.ready.begin(), scheduler.ready.end(), compareNextProcesses);

    //process bursts

    Process workingCPUprocess = scheduler.ready.back();
    scheduler.ready.pop_back();
    incrementCPU(&workingCPUprocess);

    log_cpuburst_execution(workingCPUprocess.procID,workingCPUprocess.cpuExecutedTime,
                           workingCPUprocess.ioExecutedTime,workingCPUprocess.totalElapsedTime,
                           ENTER_IO);



    if(!scheduler.blockedIO.empty()) {
        Process workingIOprocess = scheduler.blockedIO.back();
        scheduler.ready.pop_back();

        scheduler.blockedIO.push_back(workingCPUprocess);
        stable_sort(scheduler.blockedIO.begin(), scheduler.blockedIO.end(), compareNextProcesses);

        unsigned int burst = decrementBursts(&scheduler.blockedIO.front(),workingCPUprocess.bursts.front());
        incrementIO(&scheduler.blockedIO.front(),burst);

    }else {
        scheduler.blockedIO.push_back(workingCPUprocess);
    }

    while(true)
    pthread_exit(0);
}