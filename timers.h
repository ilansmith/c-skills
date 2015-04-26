#ifndef _TIMERS_H_
#define _TIMERS_H_

/* register a timer to be set when running call_timers()
   func - function to be run when timer expires
   delay - timer expiry duration

   return: 0 if timer is register successfuly, -1 otherwise
 */
int timer_add(void (*func)(void), int delay);

/* set all registered timers, execute each timer's func() when it expires */
void call_timers(void);

#endif

