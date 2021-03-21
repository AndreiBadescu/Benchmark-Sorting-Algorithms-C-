#include "../utilities.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

void selectionSort(int arr[])
{
    int i, j, min_idx;
    for (i = 1; i < arr[0]; i++)
    {
        min_idx = i;
        for (j = i+1; j <= arr[0]; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
}

int main()
{
    int *arr = read_array();
    auto start = high_resolution_clock::now();
    selectionSort(arr);
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
