#include "pm.h"
#include "mproc.h"
#include <minix/callnr.h>
#include <minix/com.h>
#include <signal.h>


int do_sam_getdpids (void){

int childCount = 0;    //set a counter for number of children
int pidrec = m_in.m1_i1;
printf("the pid for the parent process is %d\n", pidrec);
for(int countz = 0; countz < NR_PROCS ; countz++){
int processInd = mproc[countz].mp_parent;   // using vlaue from counter get the pind
int ppid = mproc[processInd].mp_pid;

if(ppid < pidrec){ 
  continue;
}

while(ppid > pidrec){
  processInd = mproc[processInd].mp_parent;
  ppid = mproc[processInd].mp_pid;
}

if(pidrec == ppid){
  int currentProcess = mproc[countz].mp_pid;
  mp->mp_reply.m_u32.data[childCount] = currentProcess;
  childCount++;
}
}
return childCount;
}

  // Set the m_u32 array zeroth element to the top process
//  mp->mp_reply.m_u32.data[0] = top;

  // Start m32Index at 1 because the zeroth element of the m_u32 array is already set to the top pid
//  int m32Index = 1;

/*  for(int i = 0; i < NR_PROCS; i++){

    // mproc[mproc[i].mp_parent].mp_pid ==> get current process's parent index in mproc
    // and then use that index to get its pid and then compare it with the top process
    if(mproc[mproc[i].mp_parent].mp_pid == top){

      // Set the m_u32 array index starting from m32Index = 1
      // because the zeroth is occupied by the top process
      mp->mp_reply.m_u32.data[m32Index++] = mproc[i].mp_pid;
    }

  }  */

  // i starts at 1 because all of the top's children have already been found
  // use m32Index as limit so that the bound is initially based on the number of children
  // added to the m_u32 array in the previous loop, m32Index will be incremented as new children are found
/*  for (int i = 1; i < m32Index; i++){

    for(int j = 0; j < NR_PROCS; j++){

      if(mp->mp_reply.m_u32.data[i] == (uint32_t) mproc[mproc[j].mp_parent].mp_pid){
          mp->mp_reply.m_u32.data[m32Index++] = mproc[j].mp_pid;
      }
    }
  }

  return 0;  */
