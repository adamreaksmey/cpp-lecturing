#include <iostream>
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    mergeSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}