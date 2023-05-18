#include <iostream>
#include <thread>
void thread_function()
{
    //this_thread.getId() returns the cuurent thread id which executes this method
    std::cout<<"Inside Thread :: ID  = "<<std::this_thread::get_id()<<std::endl;    
}
int main()  
{
    std::thread threadObj1(thread_function);
    std::thread threadObj2(thread_function);
 
    if(threadObj1.get_id() != threadObj2.get_id())
        std::cout<<"Both Threads have different IDs"<<std::endl;    
    std::cout<<"Id of thread objects  thread1= "<<threadObj1.get_id()<<" thread2 = "<<threadObj2.get_id()<<std::endl;    
 
    threadObj1.join();    
    threadObj2.join();    
    return 0;
}