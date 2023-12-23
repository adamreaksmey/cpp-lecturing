#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
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

    // Measure the start time for selection sort
    clock_t selectionSortStartTime = clock();

    selectionSort(arr, ARRAY_SIZE);

    // Measure the end time for selection sort
    clock_t selectionSortEndTime = clock();

    cout << "Sorted Array using Selection Sort: ";
    printArray(arr, ARRAY_SIZE);

    // Calculate the elapsed time for selection sort in seconds
    double selectionSortElapsedTime = double(selectionSortEndTime - selectionSortStartTime) / CLOCKS_PER_SEC;

    cout << "Elapsed Time: " << selectionSortElapsedTime << " seconds" << endl;

    return 0;
}