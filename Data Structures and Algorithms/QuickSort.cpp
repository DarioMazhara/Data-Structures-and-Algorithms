//
//  QuickSort.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/12/22.
//

#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

class QuickSort {
public:
    
    int partition(int arr[], int low, int high) {
        
        int pivot = arr[high];
        
        int i = (low-1);
        
        for (int j = low; j < high - 1; j++) {
            
            if (arr[j] < arr[i]) {
                
                i++;
                int temp = arr[j];
                arr[j] = arr[i];
                
                arr[i] = temp;
                
            }
            
            int temp = arr[i + 1];
            arr[i+1] = arr[high];
            arr[high] = temp;
            
            return (i+1);
        }
        return 0;
    }
  
    
    void quickSort(int arr[], int low, int high) {
        
        if (low < high) {
            
            int p = partition(arr, low, high);
            
            quickSort(arr, low, p-1);
            quickSort(arr, p+1, high);
        
        }
        
    }
};
