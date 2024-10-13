#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <pthread.h>


#include "log.h"
#include "process.h"
#include "scheduler.h"

using namespace std;



vector<unsigned int> extractBursts(string buffer);

int main(int argc, char *argv[]) {

  int opt;
  double alpha = 0;

  //TODO test getop switch case

  //seeks Alpha Option
  while((opt = getopt(argc, argv, "a:")) != -1) {
    switch(opt)
    {
      case 'a':
        alpha = std::stod(optarg);
        if( 0 < alpha && alpha < 1 ) {
          printf("alpha = %f",alpha);
          continue;
        }
        printf("Alpha for exponential averaging must be within (0.0, 1.0) \n");
        exit(21);
      case ':':
        printf("Option requires a value\n");
        exit(22);
      case '?':
        printf("Invalid option \"%s\" entered exiting....\n", argv[optind]);
        exit(23);
    }
  }

  ifstream input(argv[optind]);

  if(!input) {
    printf("Error opening file %s\n", argv[1]);
    exit(2);
  }

  vector<Process> processes;

  string buffer;

  for(int i = 0; getline(input,buffer); i++) {
    Process proc(extractBursts(buffer), i);
    processes.push_back(proc);
  }

  pthread_t threads;

  do {

  }while(!SharedData.waiting())

  //TODO implement this and compare in scheduler.h
  //stable_sort(processes.begin(),processes.end(),compareProcs);




  return 0;
}

//method
vector<unsigned int> extractBursts(string buffer) {
  vector<unsigned int> burstArr;
  size_t pos = 0;
  string delim = " ";
  string token;
  while((pos = buffer.find(delim)) != string::npos)  {
    token = buffer.substr(0, pos);
    burstArr.push_back(stoi(token));
    buffer.erase(0, pos + delim.length());
  }
  //shrink memoryspace of vector to conserve some bits
  burstArr.shrink_to_fit();
  return burstArr;
}
