#include <stdio.h>
#include <time.h>
int
main()
{
	printf("#define SIZEOF_TIME_T %ld\n", sizeof(time_t));
	return (0);
}
