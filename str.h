#ifndef STR_H
#define STR_H

extern unsigned int str_copy();

/* DKIM 1.10
extern unsigned int str_copyb();
   end DKIM 1.10 */

extern int str_diff();
extern int str_diffn();
extern unsigned int str_len();
extern unsigned int str_chr();
extern unsigned int str_rchr();
extern int str_start();

/* DKIM 1.10 */
#include <sys/types.h>
extern size_t str_cspn();
/* end DKIM 1.10 */

#define str_equal(s,t) (!str_diff((s),(t)))

#endif
