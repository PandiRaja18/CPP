#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>
 
std::timed_mutex test_mutex;
 
void f()
{
    auto now=std::chrono::steady_clock::now();
    test_mutex.try_lock_until(now + std::chrono::seconds(10));
    std::cout <<"Hello world"<<std::endl;  //endl mostly execute at last because within that time period 'hello world' in another thread will get execute.  
}
 
int main()
{
    std::lock_guard<std::timed_mutex> l(test_mutex);
    std::thread t(f);
    std::thread t2(f);
    t.join();
    t2.join();
}