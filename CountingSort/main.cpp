#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>

using namespace std::chrono;

int* read_array(){
    std::ifstream fin("C:\\Users\\Andrei\\Desktop\\Proiect MPI\\Tests\\Counting Sort\\DATA 1e+4.txt");
    if(!fin)
        return 0;

    int n;
    fin >> n;
    int *arr = new int[n + 1];
    arr[0] = n;
    for(int i = 1; i <= n; ++i){
        fin >> arr[i];
    }

    return arr;
}

bool check_array(int arr[]){
    for(int i = 1; i < arr[0]; ++i){
        if(arr[i] > arr[i + 1])
            return 0;
    }
    return 1;
}

void countSort(int arr[])
{
    int i;
    long long maxim = -2147483648;
    long minim = 2147483647;

    for(i = 1; i <= arr[0]; ++i){
        if(arr[i] > maxim)
            maxim = arr[i];
        if(arr[i] < minim)
            minim = arr[i];
    }

    long long range = maxim - minim + 1;

    int *count = new int[range];
    int *output = new int[arr[0] + 1];

    memset(count, 0, sizeof(*count));

    for (i = 1; i <= arr[0]; ++i)
        ++count[arr[i] - minim];

    for (i = 1; i < range; ++i)
        count[i] += count[i - 1];

    for (i = arr[0]; i > 0; --i) {
        output[count[arr[i] - minim]] = arr[i];
        --count[arr[i] - minim];
    }

    for (i = 1; i <= arr[0]; ++i)
        arr[i] = output[i];

    delete[] count;
    delete[] output;
}

int main()
{
    int *arr = read_array();
    auto start = high_resolution_clock::now();
    countSort(arr);
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
