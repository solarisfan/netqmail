
#ifndef FAILEDDN_H
#define FAILEDDN_H

extern int failedDN_on_list(char *);
extern int failedDN_add(char *);
extern int failedDN_del(char *);
extern int failedDN_get_all(void (*)(char *));
extern int failedDN_get_keys(void(*)());

#endif
