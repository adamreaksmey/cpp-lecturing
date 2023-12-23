#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n, int rootIndex)
{
    int largest = rootIndex;
    int leftChild = 2 * rootIndex + 1;
    int rightChild = 2 * rootIndex + 2;

    if (leftChild < n && arr[leftChild] > arr[largest])
    {
        largest = leftChild;
    }

    if (rightChild < n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != rootIndex)
    {
        swap(arr[rootIndex], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Measure the start time
    clock_t startTime = clock();

    heapSort(arr, ARRAY_SIZE);

    // Measure the end time
    clock_t endTime = clock();

    cout << "Sorted Array using Heap Sort: ";
    printArray(arr, ARRAY_SIZE);

    // Calculate the elapsed time in seconds
    double elapsedTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Elapsed Time " << elapsedTime << " seconds" << endl;

    return 0;
}