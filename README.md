c-skills
========
In this question you must implement a simple timer library.
The working directory contains the following files:

- timers.c:      implementation of the timer functions-
                 YOU NEED TO FILL IT IN !!!
- timers.h:      declaration of the different timer functions
- libsys.a:      system library with the backing infrastructure you'll be
                 needing
- sys.h:         declaration of the system functions available to you in
                 libsys.a (API)
- timers_test.o: a pre-compiled test application object (main) for testing
                 your code
- Makefile:      a makefile for building your code and the timers_test testing
                 application

You must fill in the following functions in timers.c:
- int timer_add(void (*func)(void), int delay);
- void call_timers(void);

Here's a simple example that demonstrates the expected behavior of the library:

        ================== tiemrs_test.c ================== 
        #include "lib.h"
        
        int main(int argc, char *argv[])
        {
                timer_add(cb_1, 3);
                timer_add(cb_2, 7);
                call_timers();
    
                return 0;
        }
        =================================================== 

This application sets some callbacks using timer_add(), then calls
call_timers(). call_timers() will call cb_1() after 3 seconds, and 4 seconds 
later cb_2() will be called. Once cb_2() is done, call_timers() returns.

You may use the accessory function do_sleep() from the OS (declared in sys.h):
- void do_sleep(int seconds);

A few points of importance:
- You are writing an API that its users can use as they please (no conditions
  can be put on the API, except for the fact that call_timers() is called after 
  all the timers have been added with timer_add()).
- Make sure that your code is bug free.
- Try to make your code as short and efficient as possible.

