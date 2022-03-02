//
//  BubbleSort.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/10/22.
//

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
class BubbleSort {
public:
    void swap(int *x, int *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    
    bool isSorted(int arr[], int n) {
        for (int i = 0; i < n-1; i++) if (arr[i] > arr[i+1]) return false;
    return true;
    }
    //n = size of array
    void bubbleSort(int arr[], int n) {
        while (isSorted(arr, n)) for (int i = 0; i < n-1; i++) swap(&arr[i], &arr[i+1]);
        cout << arr[0] << endl;
    }
};

int main() {
    
    
    int* arr_ptr;
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    
    arr_ptr = &arr[0];
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    BubbleSort* bs = new BubbleSort();
    
    bs->bubbleSort(arr, n);
    
    
};
