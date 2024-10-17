#include <stdio.h>
#include "log.h"

/* Handle C++ namespaces, ignore if compiled in C 
 * C++ usually uses this #define to declare the C++ standard.
 * It will not be defined if a C compiler is used.
 */
#ifdef __cplusplus
using namespace std;
#endif

/*
 * Data section - 
 */

/* Names of producer threads and request types */
const char *executionStopReason[] = {"enter io", "quantum expired", "completed"};

/**
 * @brief 
 * 
 * @param procID 
 * @param cpuExecutedTime 
 * @param ioExecutedTime 
 * @param totalElapsedTime 
 * @param stopReason 
 */
void log_cpuburst_execution (unsigned int procID, 
                             unsigned int cpuExecutedTime,
                             unsigned int ioExecutedTime,
                             unsigned int totalElapsedTime,
                             ExecutionStopReasonType stopReason) {

  // print according to this format
  // P0: cpu executed = 3, io executed = 0, time elapsed = 3, enter io
  printf("P%d: cpu executed = %d, io executed = %d, time elapsed = %d, %s\n", 
         procID, cpuExecutedTime, ioExecutedTime, totalElapsedTime,
         executionStopReason[stopReason]);
}

/**
 * @brief 
 * 
 * @param bursts - 1D array of integers
 */
void log_process_bursts (unsigned int procID, unsigned int bursts[], unsigned int numOfBursts) {

  printf("P%d: ", procID);

  for (int i = 0; i < numOfBursts; i++) {
    // Print integers on one line.
    printf("%d ", bursts[i]);
  }

  printf("\n");  
} 

/**
 * @brief log the estimated bursts from exponential averaging
 * 
 * @param bursts - 1D array of floating points
 */
void log_process_estimated_bursts (unsigned int procID, float bursts[], unsigned int numOfBursts) {

  printf("P%d: ", procID);

  for (int i = 0; i < numOfBursts; i++) {
    // Print integers on one line.
    printf("%.2f ", bursts[i]);
  }

  printf("\n");

  /* This is not really needed, but will be helpful for making sure that you
  * see output prior to a segmentation violation.  This is not usually a
  * good practice as we want to avoid ending the CPU burst premaurely which
  * this will do, but it is a helpful technique.
  */
  // fflush(stdout);  
}

/**
 * @brief 
 * 
 * @param procID 
 * @param completionTime 
 * @param totalWaitTime 
 */
void log_process_completion (unsigned int procID, 
                             unsigned int completionTime,
                             // wait time is the time spent in the ready queue
                             // wait time = completionTime - total cpu bursts - total io bursts
                             unsigned int totalWaitTime) {

  // print according to this format
  printf("P%d: turnaround time = %d, wait time = %d\n", 
         procID, completionTime, totalWaitTime);
}

