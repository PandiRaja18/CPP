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
    mutex mtx;
};
void transfer(Bank &from,Bank &to,int amount)
{
    if(&from == &to)
    {
        cout <<"Cannot Transfer to same account";
        return;
    }
    //if i use adopt_lock in unique_lock it will thrown run time error because it expects an locked mutex
    /*
    terminate called recursively
    terminate called after throwing an instance of 'std::system_error'
    */
    unique_lock lock1{from.mtx,defer_lock};
    unique_lock lock2{to.mtx,defer_lock};
    lock(lock1,lock2);
    from.balance-=amount;
    to.balance+=amount;   
}
int main()
{
    Bank acc1{1000};
    Bank acc2{500};
    thread transaction1{transfer,ref(acc1),ref(acc2),300};
    thread transaction2{transfer,ref(acc2),ref(acc1),100};
    transaction1.join();
    transaction2.join();
    cout<<"Acount 1 Balance :"<<acc1.balance<<endl;
    cout<<"Acount 2 Balance :"<<acc2.balance<<endl;
    return 0;
}