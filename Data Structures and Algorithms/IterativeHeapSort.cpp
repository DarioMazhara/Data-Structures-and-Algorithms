#include <iostream>

using namespace std;

void maxHeap(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[(i-2)/2]) {
            int j = i;

            //swap child and parent till parent smaller
            while (arr[j] > arr[(j-1)/2]) {
                swap(arr[j], arr[(j-1)/2]);
                j = (j-1)/2;
            }
        }
    }
}

void heapSort(int arr[], int n) {
    maxHeap(arr, n);

    for (int i = n-1; i > 0; i++) {
        swap(arr[0], arr[i]);

        int j =0, index;
        do {
            index = 2 * j + 1;

            if (arr[index] < arr[index+1] && index < (i-1))
                index++;
            
            if(arr[j] < arr[index] && index < i)
                swap(arr[j], arr[index]);
            j =index;

        } while (index < i);
    }
}