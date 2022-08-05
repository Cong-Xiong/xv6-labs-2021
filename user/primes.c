//Cong 2022/08/05

#include "kernel/types.h"
#include "user/user.h"

int p[2];	

void
execute()
{ 
  int number;
  int prime;
  int p2[2];
  if(read(p[0],&prime,4)==0)return;
  printf("prime %d\n", prime);
  pipe(p2);
  if(fork()!=0){ 
    close(p2[0]);
    while(1){
      if(read(p[0],&number,4)==0)break;
      if(number%prime!=0)write(p2[1],&number,4);
    }
	close(p[0]);
    close(p2[1]);
    wait(0);
  }else{
    close(p2[1]);
	close(p[0]);
    p[0]=dup(p2[0]);
    execute();
	close(p[0]);
  }
 
}

int 
main (int argc, char *argv[]) 
{
  int i;
  pipe(p);

  if(fork()==0){
    close(p[1]);
	execute();
    close(p[0]);
  } else{
	close(p[0]);
	for(i=2; i < 36; i++){
	  write(p[1], &i, 4);
	}
	close(p[1]);
	wait(0);
  }

  exit(0);
}

