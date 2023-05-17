#include <iostream>
#include <thread>

int sharedStaticVariable = 0;

void IncrementStaticVariable() {
    for (int i = 0; i < 1000000; ++i) {
        sharedStaticVariable++;  // Increment the static variable
    }
}

int main() {
    std::thread thread1(IncrementStaticVariable);
    std::thread thread2(IncrementStaticVariable);

    thread1.join();
    thread2.join();

    std::cout << "Final value of sharedStaticVariable: " << sharedStaticVariable << std::endl;

    return 0;
}
