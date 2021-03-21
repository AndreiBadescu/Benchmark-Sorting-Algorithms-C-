#include "../utilities.h"
#include <iostream>
#include <chrono>

using namespace std::chrono;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = new int[n1], *R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

int main()
{
    int *arr = read_array();
    auto start = high_resolution_clock::now();
    mergeSort(arr, 1, arr[0]);
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
