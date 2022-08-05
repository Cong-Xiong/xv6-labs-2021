#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc < 2){
    fprintf(2,"Need a number\n");
    exit(1);
  }
  
  if(argc > 2){
    fprintf(2,"Too many arguements\n");
    exit(1);
  }
  
  sleep(atoi(argv[1]));
  exit(0);
}

