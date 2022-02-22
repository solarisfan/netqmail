#ifndef BASE64_H
#define BASE64_H

/* DKIM-1.10 */
#include "stralloc.h"
extern int b64decode(const unsigned char *, int, stralloc *);
extern int b64encode(stralloc *, stralloc *);
/* end DKIM-1.10 */

extern int b64decode();
extern int b64encode();

#endif
