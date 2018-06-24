
#include <sys/cdefs.h>
#include <lib.h>
#include "namespace.h"
#include <string.h>
#include <sys/time.h>

void sam_time(int * sec, int * nsec)
{
  message m;

  memset(&m, 0, sizeof(m));
//  m.m_lc_pm_time.clk_id = clock_id;

  _syscall(PM_PROC_NR, PM_SAM_TIME, &m);

  * sec = m.m_pm_lc_time.sec;
  * nsec = m.m_pm_lc_time.nsec;

}
