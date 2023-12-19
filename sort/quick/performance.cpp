#include <iostream>
#include <cstdlib>
#include <ctime>
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