// thread example
#include <iostream>       
#include <thread>    
 
void foo() 
{
 std::cout<<"Thread1"<<std::endl;
}

void bar(int x)
{
  std::cout<<"Thread2 :"<< x<<std::endl;
}

int main() 
{
  std::thread first (foo);     
  std::thread second (bar,0);  

  // synchronize threads:
  
  std::cout << "main, foo and bar now execute concurrently...\n";    //main thread has to wait until two threads were executed    
  first.join(); 
  std::cout << "foo and bar completed.\n";
  //second.join();
  

  return 0;
}