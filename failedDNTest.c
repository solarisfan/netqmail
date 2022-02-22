#include <stdio.h>
#include "failedDN.h"

static void dump(char *s) {
	printf("%s\n", s);
}
int main() {
	printf("Add\n");
	failedDN_add("abc.com");
	failedDN_get_all(dump);
	printf("Delete\n");
	failedDN_del("abc.com");
	failedDN_get_all(dump);
	failedDN_add("def.com");
	failedDN_get_keys(dump);
	return 0;
}
