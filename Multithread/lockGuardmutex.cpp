#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
struct Bank
{
    int balance;
    Bank(int amount)
    {
        balance = amount;
    }
    mutex mtx1,mtx2;
};
void transfer(Bank &from,Bank &to,int amount)
{
    if(&from == &to)
    {
        cout <<"Cannot Transfer to same account";
        return;
    }
    lock(from.mtx1,to.mtx2);
    //Lock_guard create a RAII wrapper and takes the ownership of the mutex and deallocate the memory/unlock automatically once it is out of scope.
    lock_guard lock1{from.mtx1,adopt_lock};
    lock_guard lock2{to.mtx2,adopt_lock};
    //commenting the above two line will also work fine but the thread remains unlocked.
    from.balance-=amount;
    to.balance+=amount;   
}
/*
Testing phase for program crash if the above threads remain locked...
void transfer2(Bank &from,Bank &to,int amount)
{
    if(&from == &to)
    {
        cout <<"Cannot Transfer to same account";
        return;
    }
    lock(to.mtx1,from.mtx2);
    lock_guard lock1{from.mtx1,adopt_lock};
    lock_guard lock2{to.mtx2,adopt_lock};
    from.balance-=amount;
    to.balance+=amount;   
}
*/
int main()
{
    Bank acc1{1000};
    Bank acc2{500};
    thread transaction1{transfer,ref(acc1),ref(acc2),300};
    thread transaction2{transfer,ref(acc2),ref(acc1),100};
    //thread transaction3{transfer2,ref(acc1),ref(acc2),100};
    transaction1.join();
    transaction2.join();
    //transaction3.join();
    
    cout<<"Acount 1 Balance :"<<acc1.balance<<endl;
    cout<<"Acount 2 Balance :"<<acc2.balance<<endl;
    return 0;
}