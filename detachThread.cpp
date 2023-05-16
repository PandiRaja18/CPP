#include <iostream>
#include <thread>
#include <chrono>
void thread_waiting(int n)
{
	std::this_thread::sleep_for (std::chrono::seconds(n));
	std::cout << "The main thread will pause for " << n << " seconds ended\n";
}
void detach_func()
{
	std::cout << "It will freeup the resource and detaching 3 threads...\n";
	
	//detach() method detach the thread from the parent thread then execute it independently depends on process time.
	//After executed, the memory allocated for this thread will be given to OS.
	std::thread (thread_waiting,1).detach();
	std::thread (thread_waiting,2).detach();
	std::thread (thread_waiting,3).detach();
	
	// join will wait fir the respective time specified in thread_wating method and then move to the parent thread 
	/*std::thread (thread_waiting,1).join();
	std::thread (thread_waiting,2).join();
	std::thread (thread_waiting,3).join();
	*/
	std::cout << "Done with releasing of threads.\n";
}
void thread_call()
{
	std::cout << "Starting the thread call and then apply detach function.\n";
	detach_func();
	std::cout << "Exiting the thread call after applying detach function.\n";
}
int main()
{
	thread_call();
	std::cout << "(the main thread will now pause for 5 seconds)\n";
	thread_waiting(5);
	return 0;
}