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
 * 
 *  To understand the nested for loops,
 *  we must compute it from the inside first.
*/

void bubbleSort(int arr[], int n)
{
    // Function to perform Bubble Sort on an array

    /**
        `i` < `n` - 1: The loop continues as long as the pass number `i`
        is less than `n` - 1. Here's the rationale behind this condition:

        `n` : Represents the total number of elements in the array.
        `i` : Represents the pass number. The algorithm performs a pass for 
        each element in the array, excluding the last element after each pass. 
        This is because, after each pass, the largest unsorted element is 
        correctly placed at the end of the array.
        So, `n` - 1 ensures that the loop stops when the 
        last pass is reached, and the array is fully sorted.
    */
    for (int i = 0; i < n - 1; ++i)
    {
        /**
            `j < n - 1 - i` : The loop continues as long as the index `j` is less than `n - 1 - i`. 
            Here's the rationale behind this condition:
            `n` : Represents the total number of elements in the array.
            `i` : Represents the pass number. After each pass, the largest unsorted element
            is correctly placed at the end of the array. Therefore, in sorting rounds, 
            there is no need to check the last `i` elements because they are already in their correct positions.

            So, `n - 1 - i` ensures that the loop doesn't compare elements that are already 
            in their final sorted positions. This optimization reduces the number of 
            unnecessary comparisons, making the algorithm more efficient.
        */
        for (int j = 0; j < n - 1 - i; ++j)
        {
            // Comparing elements from the array by taking
            // the first 2 elements.
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
