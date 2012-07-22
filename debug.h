//debugging
#ifndef __DEBUG_H_
#define __DEBUG_H_
#ifdef DEBUG_ON
#define DEBUG(x) (x)
#else
#define DEBUG(x) ((void)0)
#endif
#endif
