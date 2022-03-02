//
//  SearchSortedRotatedArray.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/11/22.
//

#include "SearchSortedRotatedArray.hpp"

#include <stdio.h>
#include <iostream>
#include <math>

using namespace std;

class SearchSRArray {
    
    
    int findPivot(int arr[], int n) {
        int pivot_index;
        
        for (int i = 0; i < n-1; i++) {
            if (arr[i] > arr[i+1]) {
                pivot_index = i;
                break;
            }
        }
        return pivot_index;
    }
    
    void splitArray(int arr[], int n, int pivot, int x) {
        
        int low_arr[] = arr;
        int hi_arr[sizeof(arr[pivot])];
        
        for (int i = 0; i <= pivot; i++) {
            hi_arr[i] = arr[i];
        }
        for (int j = (pivot+1); j < n; j++) {
            low_arr[j] = arr[j]
        }
        
        int unrot_arr[] = low_arr + hi_arr;
        
        
        return binarySearch(unrot_arr, 0, n, x);
    }
    
    int binarySearch(int arr[],int s int n, int x) {
        int l = s;
        int r = n - 1;
        int m = (l + r) / 2;
        
        if (arr[m] == x)
            return m;
        
        if (x < arr[m])
            binarySearch(arr, l, m, x);
        else
            binarySearch(arr, m, r, x);
        
        return -1;
        
    }
    
    void search(int arr[], int n, int x) {
        
        splitArray(arr, n, findPivot(arr, n), x);
        
    }
    
}
