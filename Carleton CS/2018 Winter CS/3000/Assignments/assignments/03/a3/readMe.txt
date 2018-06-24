Sam Diamantstein: 101060342
COMP 3000 Assignment 3:



STEPS TAKEN

1. usr/src/minix/servers/sched/schedproc.h, I added the following field (Pid_T processGrp): 
-Image 1
2. In /usr/src/minix/include/minix/ipc,h, I added a similar field 
-Image 2
3. In /usr/src/minix/servers/pm/schedule.c in function: sched_start_usr, I added to the sched_inherit function call:
-Image 3
4. Added Pid_T processGrp variable to sched.h
-Image 4

5. Added processGrp to sched_inherit function in sched_start.c
-Image 5

6. In schedule.c I added code to two functions: do_start_scheduling And do_noquantum
- added rmp->processGrp to do_start_scheduling:  See image 7
- In do_noquantum we use the group size to divide the default Time slice in order determine how much cpu needs to be allocated per process: See image 7


7. Following the steps taken above, I rebuilt my minix
machine with "make build MKUPDATE=yes"

8. I rebooted the minix machine

9. TESTERS work:
- I ran  cc -o tester1 tester1.c. and cc -o tester2 tester2.c. along with top and took a screen shot


PROOF OF SUCCESS:

- SEE IMAGE “Success”
