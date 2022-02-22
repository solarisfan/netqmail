#include <sys/types.h>
#include <unistd.h>
#include <grp.h>
#include "exit.h"

void main()
{
 gid_t x[4];

 x[0] = x[1] = 0;
#ifdef HASSHORTSETGROUPS
 if (getgroups(1,x) == 0) if (setgroups(1,x) == -1) _exit(1);
#else
 int gid = 0;
 if (getgroups(1,x) == 0) if (setgroups(1,&gid) == -1) _exit(1);
#endif
 _exit(0);
}
