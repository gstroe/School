Created:   6/3/2008
Modified:  6/3/2008


These examples were provided with a Freescale CodeWarrior project.  

While they do provide some useful guidance, they also violate the organization of collecting "component" assets into separate folders.

Notice the following:
* main.c contains the definitions for all of the "init_..." functions.
* vectors\projectvectors.c contains the definition of the Real Time Interrupt ISR (rti_isr())

This means that these "features" or "components" are distributed throughout several files in several folders.
How does the effort to re-use one of these "distributed" components compare to that of re-using a component with all files collected in their own folder?


~Ben Sweet