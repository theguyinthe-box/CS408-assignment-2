#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include <algorithm>
#include "log.h"
#include "process.h"
#include "scheduler.h"

using namespace std;

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

  FILE *fptr = fopen(argv[optind], "r");
  if(fptr == NULL) {
    printf("Error opening file %s\n", argv[1]);
    exit(2);
  }

  int fileCursor = 0;
  while(!feof(fptr)) {

  }

  return 0;
}