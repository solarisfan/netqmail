#include <unistd.h>
#include "ndelay.h"
#include "open.h"
#include "triggerpull.h"

void triggerpull()
{
 int fd;

 fd = open_write("lock/trigger");
 if (fd >= 0)
  {
   ndelay_on(fd);
   int unused = write(fd,"",1); /* if it fails, bummer */
   close(fd);
  }
}
