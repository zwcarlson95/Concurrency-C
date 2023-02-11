Program for demonstrating concurrent programming concepts in C++. 

Two threads are created, one for counting up from 0 to 20 and the second for counting back down to 0. The second thread must wait until the first thread has finished counting to 20 before it can begin counting down to 0. Mutexes, condition variables, and unique locks are all used to achieve this goal.
