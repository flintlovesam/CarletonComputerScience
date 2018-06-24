Sam Diamantstein: 101060342
COMP 3000 Assignment 1:



STEPS TAKEN

1. Declared my system call in a new header file that I put in the directory /include/.
- See Image 1 for reference

2. Listed the name of my file in the in file /usr/src/include/Makefile.
- See Image 2

3. Defined my system call in a new .c file that I put in the directory /minix/lib/libc/sys/.
- See Image 3, and sam_time.c for reference

4. Listed the name of my file in the file minix/lib/libc/sys/Makefile.inc.
-See image 4

5. Defined my system call number in the file /minix/include/minix/callnr.h.
- See image 5

6. Declared a function in the file /minix/servers/pm/proto.h.
- See image 6

7. Registered the function into the call vector in /minix/servers/pm/table.c, that has been reserved in file /minix/include/minix/callnr.h.
- See image 7

8. Defined the function in a new .c file in the directory /minix/servers/pm.
- See image 8, and do_sam_time.c for reference


9. Included the do_sam_time function in a make file (to be safe)
 - See image 9

10. I wrote the tester.c file and placed it in the directory with my sam_time function
- see tester.c for reference

11. Following the steps taken above, I rebuilt my minix
machine with "make build MKUPDATE=yes"

12. I rebooted the minix machine

13. TESTED work:
- I ran  cc -o tester tester.c
- The I ran clear;uname -a;date; more tester.c;./tester

PROOF OF SUCCESS:

- SEE IMAGE "SUCCESS"
