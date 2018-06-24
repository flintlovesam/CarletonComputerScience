
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sam_time.h>
int main(int argc, char** args) {
   int sec, nsec;

/* get the current time */
   sam_time(&sec, &nsec);
   /* print local time */
   printf("System time is %d sec and %d nsec\n", sec, nsec);
   return 0;
}
