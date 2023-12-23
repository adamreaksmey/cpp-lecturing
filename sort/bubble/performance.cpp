#include <iostream>
#include <ctime>
#include "sort.h"
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    const int ARRAY_SIZE = 100000;

    int arr[ARRAY_SIZE];

    // Generate random numbers for the array
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        arr[i] = rand() % 10000;
    }

    cout << "Original Array: ";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Measure the start time
    clock_t startTime = clock();

    bubbleSort(arr, ARRAY_SIZE);

    // Measure the end time
    clock_t endTime = clock();

    cout << "Sorted Array: ";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Calculate the elapsed time in seconds
    double elapsedTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Elapsed Time: " << elapsedTime << " seconds" << endl;

    return 0;
}