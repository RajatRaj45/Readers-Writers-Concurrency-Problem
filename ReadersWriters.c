int Rcount;
//counts the number of readers currently reading
//initialized to 0

semaphore mutex;
//binary semaphore
//provides mutually exclusive access to change the variable RCount

semaphore chance;
//counting semaphore
//maintains a queue of processes (FIFO order) wanting access to resource

semaphore resource;
//binary semaphore
//maintains access to the shared resource

//all semaphores are initialized to 1



//Reader Process
read(){
    //entry section
    wait(chance);                       //wait in queue for its chance to get executed
    wait(mutex);
    Rcount++;
    if(Rcount==1) wait(resource);       //wait for access to resource
    signal(chance);                     //allowing next in queue to get executed    
    signal(mutex);

    //critical section
    //reading is done

    //exit section
    wait(mutex);
    Rcount--;
    if(Rcount==0) signal(resource);     //release the resource
    signal(mutex);
}



//Writer Process
write(){
    //entry section
    wait(chance);                       //wait in queue for its chance to get executed
    wait(resource);                     //wait for access to resource
    signal(chance);                     //allowing next in queue to get executed

    //critical section
    //writing is done

    //exit section
    signal(resource);                   //release the resource
}
