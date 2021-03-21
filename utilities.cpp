#include "../utilities.h"
#include <fstream>

int* read_array(){
    std::ifstream fin("C:\\Users\\Andrei\\Desktop\\Proiect MPI\\Tests\\Counting Sort\\DATA 1e+9.txt");
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
