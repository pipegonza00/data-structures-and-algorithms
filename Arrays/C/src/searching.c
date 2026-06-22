#include <stdio.h>
#include "searching.h"

int linear_search(int arr[], int n, int x){
    /*
    This searching algorithm iterates through the array and compares each element with the target value (x). 
    If a match is found, it returns the index of the matching element. If the end of the array is reached without 
    finding a match, it returns -1 to indicate that the target value is not present in the array.

    its time complexity is O(n) in the worst and average case, and O(1) in the best case when the target value is found at the first position of the array.
    */
    for(int i = 0; i < n; i++){
        if(arr[i] == x){
            return i;
        }
    }

    return -1;
}

int binary_search(int arr[], int low, int high, int x){
    /*
    Binary search is an efficient searching algorithm that works on sorted arrays. It repeatedly divides the search interval in 
    half, comparing the target value (x) with the middle element of the current interval. If the middle element matches the target 
    value, the search is successful and the index of the middle element is returned. If the target value is less than the middle 
    element, the search continues in the left half of the interval; if it is greater, the search continues in the right half. 
    This process continues until the target value is found or the search interval is empty.

    its time complexity is O(log n) in all cases, as it always divides the search interval in half.
    */
    int mid;

    if(high >= low){
        mid = low + (high - low)/2;
        
        if(arr[mid] == x) return mid;

        else if (arr[mid] > x) return binary_search(arr, low, mid - 1, x);

        else return binary_search(arr, mid + 1, high, x);
    
    }else{
        return -1;
    }

}