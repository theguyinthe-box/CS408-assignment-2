#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "log.h"
#include "process.h"
#include "scheduler.h"


int main(int argc, char *argv[]) {

  int opt;

  while((opt = getopt(argc, argv, "a")) != -1)
  {
    switch(opt)
    {
      case 'a':
          printf("option: %c\n", opt);
      break;
      case ‘f’:
        printf("“filename: %s\n”", optarg);
      break;
      case ‘:’:
        printf("“option needs a value\n”");
      break;
      case ‘?’:
        printf(“unknown option: %c\n”, optopt);
      break;
    }
  }

  printf("Hello World!\n");
  return 0;
}