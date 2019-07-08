#ifndef PSYCOPG_IRIX_SUPPORT_H
#define PSYCOPG_IRIX_SUPPORT_H

#include "psycopg/config.h"

#if defined(__sgi)
#include <sys/time.h>

#ifndef timeradd
extern HIDDEN void timeradd(struct timeval *a, struct timeval *b, struct timeval *c);
extern HIDDEN void timersub(struct timeval *a, struct timeval *b, struct timeval *c);
#endif

#ifndef timercmp
#define timercmp(a, b, cmp)          \
  (((a)->tv_sec == (b)->tv_sec) ?    \
   ((a)->tv_usec cmp (b)->tv_usec) : \
   ((a)->tv_sec  cmp (b)->tv_sec))
#endif

#endif 
#endif /* defined(__sgi) */
