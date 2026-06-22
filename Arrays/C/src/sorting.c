#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n){
    /*
    Bubble sort is a simple sorting algorithm that repeatedly steps through the list, 
    compares adjacent elements and swaps them if they are in the wrong order. 
    The pass through the list is repeated until the list is sorted. 
    The algorithm gets its name from the way smaller elements "bubble" to the top of the 
    list (beginning) while larger elements sink to the bottom (end) with each pass.

    its time complexity is O(n^2) in the worst and average case, and O(n) in the best case when the array is already sorted.
    */

    int temp;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int n){
    /* 
    Selection sort is a simple sorting algorithm that divides the input list into two parts:
    the sorted part at the left end and the unsorted part at the right end. Initially, the sorted 
    part is empty and the unsorted part is the entire list. The algorithm repeatedly selects the 
    smallest (or largest, depending on sorting order) element from the unsorted part and moves it 
    to the end of the sorted part. This process continues until the entire list is sorted.

    its time complexity is O(n^2) in all cases, as it always requires two nested loops to complete the sorting process,
    regardless of the initial order of the elements.
    */
    int temp, curr_min;

    for(int i = 0; i < n - 1; i++){
        curr_min = i;

        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[curr_min]){
                curr_min = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[curr_min];
        arr[curr_min] = temp;
    }
}

void insertion_sort(int arr[], int n){
    /* 
    This sorting algorithm iterates through the array and for each element, it compares it with the elements in 
    the sorted part and shifts the larger elements to the right until it finds the correct position for the 
    current element. This process is repeated until the entire array is sorted.

    its time complexity is O(n^2) in the worst and average case, and O(n) in the best case when the array is already sorted.
    */
    int temp, j;

    for(int i = 1; i < n; i++){
        temp = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

void merge(int arr[], int left[], int left_n, int right[], int right_n){
    /*
    This is a helper function for the merge sort algorithm. It takes two sorted subarrays 
    (left and right) and merges them into a single sorted array (arr).
    */
    int i = 0, l = 0, r = 0;

    while(l < left_n && r < right_n){
        if(left[l] < right[r]){
            arr[i] = left[l];
            l++;
            i++;
        
        } else{
            arr[i] = right[r];
            r++;
            i++;

        } 
    }

    while(l < left_n){
        arr[i] = left[l];
        i++;
        l++;
    }

    while(r < right_n){
        arr[i] = right[r];
        i++;
        r++;
    }

}

void merge_sort(int arr[], int n){
    /*
    This algorithm uses a divide-and-conquer approach to sort the array. It divides the array into two halves, 
    recursively sorts each half, and then merges the sorted halves back together. The merge step is where the 
    actual sorting happens, as it combines the two sorted halves into a single sorted array.

    its time complexity is O(n log n) in all cases, as it always divides the array into halves and processes each element once during the merge step.
    */
    int mid, j;
    
    if(n <= 1){
        return;
    }

    mid = n / 2;
    int left[mid], right[n - mid];
    
    //left half of the array
    for(int i = 0; i < mid; i++){
        left[i] = arr[i];
    }

    //right half of the array
    j = 0;
    for(int i = mid; i < n; i++){
        right[j] = arr[i];
        j++;
    }

    merge_sort(left, mid);
    merge_sort(right, n - mid);
    merge(arr, left, mid, right, n - mid);

}

int partition(int arr[], int low, int high){
    /*
    This is a helper function for the quick sort algorithm. It takes the last element as the pivot, places the pivot element 
    in its correct position in the sorted array, and places all smaller elements to the left of the pivot and all greater elements to the right of the pivot. 
    The function returns the index of the pivot element after partitioning.
    */
    int pivot = arr[high], i = low - 1, temp;

    for(int j = low; j <= high - 1; j++){
        if(arr[j] < pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }    
    }   
    
    i++;
    temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;

}


void quick_sort(int arr[], int low, int high){
    /* 
    This sorting algorithm uses a divide-and-conquer approach to sort the array. It selects a 'pivot' 
    element from the array and partitions the other elements into two subarrays, according to whether 
    they are less than or greater than the pivot. The subarrays are then sorted recursively until the 
    base case is reached, which is when the subarray has one or zero elements. The pivot element is then 
    in its final position, and the process is repeated for the left and right subarrays. d

    its time complexity is O(n log n) in the average and best case, and O(n^2) in the worst case when the smallest or largest element is always chosen as the pivot.
    */
    if(high <= low) return;

    int pivot = partition(arr, low, high);

    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);

}


void shuffle(int arr[], int n){
    /*
    This function randomly shuffles the elements of the array. It iterates through the array and for each element, 
    it generates a random index and swaps the current element with the element at the random index. This process 
    ensures that each element has an equal probability of being placed in any position in the array.

    its time complexity is O(n), as it requires a single pass through the array to shuffle the elements.
    */
    int temp, rand_index;

    for(int i = 0; i < n; i++){
        rand_index = rand() % n;
        temp = arr[i];
        arr[i] = arr[rand_index];
        arr[rand_index] = temp;
    }

}