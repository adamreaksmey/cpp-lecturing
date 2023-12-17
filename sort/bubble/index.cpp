/**
 *  Let's first initialize with our very common set up of
 *  every C++ namespace.
 */
#include <iostream>
using namespace std;

/*
    Let's first start by defining a swap function like below:
*/
void swap(int &a, int &b)
{
    // Function to swap the values of two variables
    int temp = a; // Store the value of 'a' in a temporary variable 'temp'
    a = b;        // Assign the value of 'b' to 'a'
    b = temp;     // Assign the original value of 'a' (stored in 'temp') to 'b'
}

/*
    Declaration:

    The swap function takes two integer references (int &a and int &b) 
    as parameters. Using references ( & ) allows the function to directly 
    modify the values of the variables passed in.
*/

/*
    Temporary Variable (`temp`):

    Before swapping, the current value of variable `a` is stored in a temporary
    variable named `temp`. This step is crucial to prevent the loss of the 
    original value of `a` during the swap.
*/

/*
    Swapping Values:

    The value of `a` is then assigned the value of `b`, effectively replacing the original 
    value of `a` with the value of `b`.
    The value of `b` is assigned the original value of `a`, which was stored in the 
    temporary variable `temp`. This completes the swap, and now `b` holds the original value of `a`.

*/

/*
    Result:

    After the swap function is executed, the values of variables `a` and `b` have been swapped.
    This swapping mechanism is used in sorting algorithms like Bubble Sort to rearrange 
    elements in an array by comparing and swapping adjacent elements until 
    the entire array is sorted.
*/

/**
 *  Next, let's define our sorting function!
 *  The bubbleSort.
*/

void bubbleSort(int arr[], int n)
{
    // Function to perform Bubble Sort on an array

    // Outer loop for each pass
    for (int i = 0; i < n - 1; ++i)
    {
        // Last i elements are already in place, so no need to check them

        // Inner loop for each comparison in the current pass
        for (int j = 0; j < n - 1 - i; ++j)
        {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1])
            {
                // Swap if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    // Example usage of Bubble Sort

    // Array to be sorted
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calculate the number of elements in the array
    int n = sizeof(arr) / sizeof(arr[0]);

    // Display the original array
    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform Bubble Sort
    bubbleSort(arr, n);

    // Display the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
