#include "../utilities.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

void bubbleSort(int arr[])
{
    int i,j;
    for (i = 1; i < arr[0]; ++i)
        for (j = 1; j <= arr[0] - i; ++j)
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
}

int main()
{
    int *arr = read_array();
    auto start = high_resolution_clock::now();
    bubbleSort(arr);
    auto stop = high_resolution_clock::now();
    if(check_array(arr)){
        auto duration = duration_cast<microseconds>(stop - start);
        std::cout << duration.count() << " microseconds\n";
        std::cout << duration.count() / 1000 << " milliseconds\n";
        std::cout << duration.count() / 1000 / 1000 << " seconds\n";
        std::cin.get();
        return 0;
    }
    else{
        return 1;
    }
}
