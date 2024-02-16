/*
-implement a function that finds the kth smallest element in an array using the first value as the pivot. the patition function must be used and implemented.
-xx5546ys, John Klein
-2/15/2024
-Dr. Jie Hu Meichsner
*/

#include <iostream>

// The partition function not only rearranges the array elements but also calculates
// the pivot’s index when the partition is done. Make sure your function has correct
// type and parameters

/**
 * @brief the partition function takes a pointer to an array and the low and high index
 * of the array. It then sets the pivot to the first element of the array and sets i to
 * low - 1. It then loops through the array and if the current element is less than the
 * pivot, it increments i and swaps the current element with the element at i. It then
 * swaps the element at i + 1 with the pivot and returns i + 1.
 *
 * @param arr array to partition
 * @param low the low index of the array
 * @param high the high index of the array
 * @return int index of the pivot
 */
int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = (low + 1); // start 1 index after pivot
    int j = high;      // start end of array
    while (i <= j)
    {
        while (i <= j && arr[i] <= pivot)
        { // if the current element is less than the pivot, increment i until its not or its greater than j
            i++;
        }
        while (i <= j && arr[j] > pivot)
        { // if the current element is greater than the pivot, decrement j until its not or its less than i
            j--;
        }
        if (i < j)
        { // if i is less than j, swap the elements at i and j
            std::swap(arr[i], arr[j]);
        }
        // for (int i = 0; i < sizeof(arr); i++)  std::cout << arr[i] << " "; //print array to debug
        // std::cout << std::endl;
    }
    std::swap(arr[low], arr[j]); // swap the pivot with the element at j
    // for (int i = 0; i < sizeof(arr); i++)  std::cout << arr[i] << " "; //print array to debug
    // std::cout << std::endl;
    return j;                    // return the index of the pivot
}

/**
 * @brief the kthsmallest function takes a pointer to an array, the low and high index of the array
 *
 * @param arr the array to search
 * @param low the low index of the array
 * @param high the high index of the array
 * @param k the kth smallest element to find
 */
int kthsmallest(int *arr, int low, int high, int k)
{
    if (k > 0 && k <= high - low + 1) // if k is greater than 0 and less than the size of the array high - low + 1 is the size of the array
    {
        int index = partition(arr, low, high); // get the index of the pivot and partition the array
        if (index - low == k - 1)              // index - low is the number of elements less than the pivot and k - 1 is the kth smallest element if they are equal then the pivot is the kth smallest element
            return arr[index];
        if (index - low > k - 1)                                       // if the number of elements less than the pivot is greater than the kth smallest element, then the kth smallest element is in the left subarray
            return kthsmallest(arr, low, index - 1, k);                // recursively call kthsmallest with the left subarray
        return kthsmallest(arr, index + 1, high, k - index + low - 1); // recursively call kthsmallest with the right subarray
    }
    return -1;
}

int main()
{
    int size;
    int k;

    std::cout << "plaese enter the size of the array: ";
    std::cin >> size;
    int arr[size];

    std::cout << "please enter the elements of the array: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << "please enter the kth smallest element: ";
    std::cin >> k;

    int smallest = kthsmallest(arr, 0, size - 1, k);

    if (smallest == -1)
    {
        std::cout << "Invalid input" << std::endl;
    }
    else
    {
        std::cout << "The kth smallest element is: " << smallest << std::endl;
    }
    return 0;
}