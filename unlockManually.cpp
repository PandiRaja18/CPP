#include <thread>
#include <mutex>
#include <iostream>
 using namespace std;
int counter = 0;
mutex mtx; 
void safe_increment()
{
    lock_guard lock{mtx};
    ++counter;
    cout << "Thread id :"<<this_thread::get_id() << ": " << counter << endl;
    mtx.unlock();
    ++counter; //The value here will update before we lock the second thread so ,it will leads to race condition.
    this_thread::sleep_for( chrono::seconds( 5 ) );
}
int main()
{
    cout << "Before counter value " << ": " << counter << endl;
    thread t1(safe_increment);
    thread t2(safe_increment);
 
    t1.join();
    t2.join();
    cout << "Final counter value " << ": " << counter << endl;
}