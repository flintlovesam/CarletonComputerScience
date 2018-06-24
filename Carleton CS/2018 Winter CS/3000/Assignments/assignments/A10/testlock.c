//Code writen by sammy diamantstein 101060342 on ubuntu 16.04

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>


/* Creates a write lock on a file */
int main (int argc, char* argv[])
{
  char* file = argv[1];
  int fd;
  struct flock lock;

  memset (&lock, 0, sizeof(lock));
  fd = open (file, O_WRONLY);

    fcntl (fd, F_GETLK, &lock);

    if((fd, F_GETLK, &lock) == -1) {
      printf("No such file or directory\n");  // for some reason not catching error
    }
    if(lock.l_type!=F_UNLCK){
       if(lock.l_pid == 0){
          printf("No such file or directory\n");  // so I put this here to catch errors
      }
      else{
      printf("locked with PID: ");
      printf("%d\n",lock.l_pid );
    }}

    else {
      printf("File is not locked\n" );
    }
      close (fd);
      return 0;
   }
