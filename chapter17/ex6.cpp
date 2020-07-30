/* 
Programming: Principles and Practice Using C++
Chapter 17 Exercise 6:
    This chapter does not say waht happens when you run out of memory using new. That's called memory exhaustion. Find out what happens.
    You have two obvious alternatives: look for documentation, or write program with an infinite loop that allocates but never deallocates.
    Try both. Approximately how much memory did you manage to allocate before failing.
*/
#include <iostream>

int main() {
    try {
        long long bytesSize = 0;
        int allocations = 250000000;  //250000000; * sizeof(int) gives 1GB

        while (true) {
            int* memoryToAllocate = new int[allocations];
            bytesSize += allocations * sizeof(int);
            std::cout << "Alocated :" << bytesSize << " bytes\n";
        }

        //last value before throwing std::bad_alloc
        //Alocated :140724000000000 bytes
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    } catch (...) {
        std::cerr << "Other error\n";
    }

    return 0;
}
