#include <thread>
#include <mutex>
#include <iostream>
 using namespace std;
int counter = 0;
mutex mtx; 
void safe_increment()
{
    {
        scoped_lock lock{mtx};
        ++counter;
        cout << "Thread id :"<<this_thread::get_id() << ": " << counter << endl;
    }
}
int main()
{
    cout << "Before counter value " << ": " << counter << endl;
    thread t1(safe_increment);
    thread t2(safe_increment);
 
    t1.join();
    t2.join();
}