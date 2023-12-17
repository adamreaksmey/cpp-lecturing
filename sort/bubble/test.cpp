#include <iostream>
using namespace std;

void swap(int &a, int &b)
{

    int temp = a;
    a = b;
    b = temp;
}

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

// Compilation :
int main()
{
    // Initializing Array to be sorted
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // calculates the number of elements in the array 
    // `arr` and assigns the result to the variable `n`. 
    // This step is necessary because the size of an array 
    // is not directly available as a variable and needs to be computed.
    int n = sizeof(arr) / sizeof(arr[0]);
}
