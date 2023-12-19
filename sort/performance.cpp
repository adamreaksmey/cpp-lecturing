#include <iostream>
#include <cstdlib>
#include <ctime>
#include "bubble/sort.h"
#include "quick/sort.h" 
using namespace std;

int main()
{
    const int SIZE = 1000000;
    int arr[SIZE];

    // Populate the array with random values
    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand();
    }

    // Measure the execution time
    clock_t start = clock();
    quickSort(arr, 0, SIZE - 1);
    clock_t end = clock();
    double elapsedSeconds = double(end - start) / CLOCKS_PER_SEC;

    cout << "Sorting " << SIZE << " elements took " << elapsedSeconds << " seconds." << endl;

    return 0;
}