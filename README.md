c-skills
========
Event-driven architecture (EDA) is a software architecture pattern promoting the
production, detection, consumption of, and reaction to events.

libevent implements a simple event-queue in which events are pairs comprised of
a handler callback and a context on which it operates.
The library exports two functions:

- int event_add(void(*handler)(void *data), void *ctx);
- int event_loop(void);

A program utilizing libevent starts by adding one or more initial handlers (and
corresponding contexts) to the event loop with event_add(), and then issues a
single call to event_loop() to start the event handling.

event_loop() executes the handlers in the queue one by one in order of
insertion. Each handler, when running, can hook itself or other handlers back on
the event-queue with subsequent calls to event_add().
event_loop() continuously executes the handlers on the queue until the queue is
empty, upon which it terminates and the function returns.

Use libevent to implement factorial (n!) according to the following guidelines:
- Callbacks may not be recursive, and should not include more than a single
  arithmetic operation.
  Note that adding a callback back on the event-queue does not make it
  recursive!
- Callbacks may allocate/free memory to facilitate new/old contexts.
- In a sense, callbacks are atomic in that they perform a small part of the
  calculation and exit.
  In most cases, the last thing a callback does before exiting is to add a new
  event to the event-queue.
- No need for defensive programming:
  - Assume calls to malloc() and its variants are guarenteed to succeed, you do
    not need to test their return value is non-NULL
  - No need to perform argument validity

Implement the callback fact_cps() (cps: Continuation Passing Style) in fact.c to
facilitate the calculation of factorial.
Note: you may implement more callbacks and contexts should you need them.

