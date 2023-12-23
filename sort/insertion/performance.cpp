#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    const int ARRAY_SIZE = 100000; // Size of the array for the performance test

    int arr[ARRAY_SIZE];
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        arr[i] = rand() % 10000;
    }

    cout << "Original Array: ";
    printArray(arr, ARRAY_SIZE);

    // Measure the start time for insertion sort
    clock_t insertionSortStartTime = clock();

    insertionSort(arr, ARRAY_SIZE);

    // Measure the end time for insertion sort
    clock_t insertionSortEndTime = clock();

    cout << "Sorted Array using Insertion Sort: ";
    printArray(arr, ARRAY_SIZE);

    // Calculate the elapsed time for insertion sort in seconds
    double insertionSortElapsedTime = double(insertionSortEndTime - insertionSortStartTime) / CLOCKS_PER_SEC;

    cout << "Elapsed Time " << insertionSortElapsedTime << " seconds" << endl;

    return 0;
}