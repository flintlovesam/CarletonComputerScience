#include <sam_getdpids.h>
#include <lib.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>



int sam_getdpids(pid_t top, pid_t dpids[], int len){
  message m;
  memset(&m, 0, sizeof(m));
  m.m1_i1=top;

  printf("%d top\n",top);
  _syscall(PM_PROC_NR, PM_SAM_GETDPIDS, &m);

  for(int i = 0; i<14; i++){
    dpids[i] = m.m_u32.data[i];
  }

  return 14;

}
