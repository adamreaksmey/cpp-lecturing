#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void merge(int arr[], int left[], int leftSize, int right[], int rightSize)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < leftSize && j < rightSize)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size)
{
    if (size <= 1)
    {
        return;
    }

    int mid = size / 2;
    int leftSize = mid;
    int rightSize = size - mid;

    int *left = new int[leftSize];
    int *right = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        left[i] = arr[i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        right[i] = arr[mid + i];
    }

    mergeSort(left, leftSize);
    mergeSort(right, rightSize);

    merge(arr, left, leftSize, right, rightSize);

    delete[] left;
    delete[] right;
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

    // Measure the start time for merge sort
    clock_t mergeSortStartTime = clock();

    mergeSort(arr, ARRAY_SIZE);

    // Measure the end time for merge sort
    clock_t mergeSortEndTime = clock();

    cout << "Sorted Array using Merge Sort: ";
    printArray(arr, ARRAY_SIZE);

    // Calculate the elapsed time for merge sort in seconds
    double mergeSortElapsedTime = double(mergeSortEndTime - mergeSortStartTime) / CLOCKS_PER_SEC;

    cout << "Elapsed Time: " << mergeSortElapsedTime << " seconds" << endl;

    return 0;
}