#define PSYCOPG_MODULE
#include "psycopg/psycopg.h"
#include "psycopg/irix_support.h"

#if defined(__sgi)
#ifndef timeradd
void
timeradd(struct timeval *a, struct timeval *b, struct timeval *c)
{
    c->tv_sec = a->tv_sec + b->tv_sec;
    c->tv_usec = a->tv_usec + b->tv_usec;
    if (c->tv_usec >= 1000000) {
        c->tv_usec -= 1000000;
        c->tv_sec += 1;
    }
}

void
timersub(struct timeval *a, struct timeval *b, struct timeval *c)
{
    c->tv_sec = a->tv_sec - b->tv_sec;
    c->tv_usec = a->tv_usec - b->tv_usec;
    if (c->tv_usec < 0) {
        c->tv_usec += 1000000;
        c->tv_sec -= 1;
    }
}
#endif /* timeradd */
#endif /* defined(__sgi) */
