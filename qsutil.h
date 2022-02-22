#ifndef QSUTIL_H
#define QSUTIL_H

extern void log1();
extern void log2qs();
extern void log3();
extern void logsa();
extern void nomem();
extern void pausedir();
extern void logsafe();

#define log2(x, y) log2qs(x, y)

#endif
