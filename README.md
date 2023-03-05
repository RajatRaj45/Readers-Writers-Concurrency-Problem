The Readers-Writers problem is one of the most common concurrency problem in computer science.
It involves a shared resource(file) and some reader and writer processes/threads which are trying to access the resource for reading and writing.
Many reader threads can access the resource for reading at the same time.
But only one writer thread is allowed to write at a time.
Also when a reader thread is accessing the resource the writer thread is not allowed and vice versa.
This requires the need for proper synchronization between the reader and writer threads.
The attached pseudocode provide a way to solve this concurrency problem using semaphores, and it is completely starvation free.


Explanation of the pseudocode:

A variable is maintained to count the number of readers in the critical section.

Three semaphores are used for synchronization- mutex, resource and chance.

mutex: it is a binary semaphore. It is used to provide mutually exclusive access to increment or decrement the readCount variable.

resource: it is also a binary semaphore. It maintains mutually exclusive access to the shared resource/file.

chance: it is a counting semaphore. It is used to maintain a queue of processes which are wanting access to the shared resource/file.

Now, whenever any process (reader/writer) comes for execution, it waits in the queue maintained by the counting semaphore 'chance'.
These processes get chance to get executed in the order of their arrival i.e. in FIFO order.
One process is picked from the queue and it gets exclusive access of the shared resource(file) for execution.
But if there are consequtive readers in the queue, these are allowed to get the shared resource at the same time to read.

Thus consequtive readers can read at the same time and mutual exclusion is maintained between reader-writer and writer-writer processes.

In this way, all the processes/threads whether it be a reader process or writer process get a fair chance to get executed and no process is prone to starvation.
