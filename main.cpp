#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "log.h"
#include "process.h"
#include "scheduler.h"


int main(int argc, char *argv[]) {

  int opt;

//@TODO: finish writing the getopt switch case

  while((opt = getopt(argc, argv, "a:")) != -1)
  {
    switch(opt)
    {
      case 'a':
          printf("option: %c\n", opt);
      break;
      case ':':
        printf("Option requires a value\n");
      break;
      default:
    }
  }

  printf("Hello World!\n");
  return 0;
}