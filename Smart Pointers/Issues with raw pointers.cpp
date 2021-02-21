/*
Uninitialised wild pointers -> Uninitialised pointers can point anywhere in memory and
                               if we try to strore data, we could have potentially catastrophic
                               results.
Memory leaks -> When we don`t deallocate the memory allocated on heap.
                This case will leak memory.

Dangling pointers ->  Pointer pointing to storage that it thinks is valid but already been deallocated.


Not exception safe -> If exceptions are thrown in program and the code which releases the memory is never executed and will leak memory.

*/
