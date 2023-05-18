#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;
mutex mtx1;
mutex mtx2;

void function1() {
    unique_lock<mutex> lock1(mtx1, defer_lock);
    unique_lock<mutex> lock2(mtx2, defer_lock);
    if (timed_lock(lock1, lock2, chrono::seconds(5))) {
        cout << "Function 1: Acquired locks on mtx1 and mtx2" << endl;
        cout << "Function 1: Released locks on mtx1 and mtx2" << endl;
    } else {
        cout << "Function 1: Time out" << endl;
    }
}

void function2() {
    unique_lock<mutex> lock1(mtx1, defer_lock);
    unique_lock<mutex> lock2(mtx2, defer_lock);
    if (timed_lock(lock1, lock2, chrono::seconds(2))) {
        cout << "Function 2: Acquired locks on mtx1 and mtx2" << endl;
        cout << "Function 2: Released locks on mtx1 and mtx2" << endl;
    } else {
        cout << "Function 2: Time out" << endl;
    }
}

int main() {
    thread t1(function1);
    thread t2(function2);
    t1.join();
    t2.join();
    return 0;
}
