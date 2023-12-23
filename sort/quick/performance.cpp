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

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
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

    // Measure the start time for quicksort
    clock_t quickSortStartTime = clock();

    quickSort(arr, 0, ARRAY_SIZE - 1);

    // Measure the end time for quicksort
    clock_t quickSortEndTime = clock();

    cout << "Sorted Array using Quicksort: ";
    printArray(arr, ARRAY_SIZE);

    // Calculate the elapsed time for quicksort in seconds
    double quickSortElapsedTime = double(quickSortEndTime - quickSortStartTime) / CLOCKS_PER_SEC;

    cout << "Elapsed Time: " << quickSortElapsedTime << " seconds" << endl;

    return 0;
}