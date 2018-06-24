

#include <stdio.h>
#include <unistd.h>

int main(){
  printf("process ID is %d\n", (int) getpid () );
  printf("parent process ID is %d\n", (int) getppid () );
  printf("User ID is %d\n", (int) getuid () );
  return 0;
  
}
