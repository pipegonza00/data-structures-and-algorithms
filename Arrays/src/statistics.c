#include "statistics.h"

int find_min(int arr[], int n){
    int min = arr[0];

    for(int i = 0; i < n; i++){
        if(arr[i] < min) min = arr[i];
    }
    
    return min;
}

int find_max(int arr[], int n){
    int max = arr[0];

    for(int i = 0; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }

    return max;
}

double find_average(int arr[], int n){
    double acum = 0, average = 0;

    for(int i = 0; i < n; i++){
        acum += arr[i];
    }
    
    average = acum / n;

    return average;
}

int find_median(int arr[], int n){
    int median, mid;
    mid = n / 2;

    if(n%2 == 0) median = (arr[mid] + arr[mid + 1]) / 2;

    else median = arr[mid];

    return median;
}

int find_mode(int arr[], int n){
    int mode = 0, max_count = 0, max_val = find_max(arr, n);
    int freq_arr[max_val + 1];

    for(int i = 0; i <= max_val; i++) freq_arr[i] = 0;

    for(int i = 0; i < n; i++) freq_arr[arr[i]]++;

    for(int i = 0; i <= max_val;  i++){
        
        if(freq_arr[i] > max_count){
            max_count = freq_arr[i];
            mode = i;
        }
    }

    return mode;
}

int sum_array(int arr[], int n){
    int sum = 0;

    for(int i = 0; i < n; i++) sum += arr[i];

    return sum;
}