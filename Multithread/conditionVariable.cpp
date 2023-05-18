#include<thread>
#include<mutex>
#include<condition_variable>
#include<iostream>
using namespace std;
class Directory{
    mutex mtx;
    condition_variable cond;
    int Data;
    public :
        
        Directory()
        {
            Data = 0;
        }
        int isDataPresent()
        {
            return Data;
        }
        void processing()
        {
            this_thread::sleep_for(chrono::milliseconds(2000));
            cout<<"Data is loading is in progress"<<endl;
            mtx.lock();
            Data=1;
            cond.notify_one();
            mtx.unlock();
        }
        void checkData()
        {
            cout<<"Enter into the directory"<<endl;
            unique_lock lock1(mtx);
            cond.wait(lock1,[this]{return isDataPresent() == 1;});
            cout <<"Data loaded succesfully"<<endl;
        }
};
int main()
{
   Directory dir;
   thread thread_1(&Directory::checkData, &dir);
   thread thread_2(&Directory::processing, &dir);
   thread_1.join();
   thread_2.join();
   return 0;
}
