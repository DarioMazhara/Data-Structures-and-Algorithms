#include <iostream>

using namespace std;

void merge(int arr[], int l, int r, int m) {
    auto const subArr1 = m - l + 1;
    auto const subArr2 = r - m;

    auto *leftArr = new int[subArr1];
    auto *rightArr = new int[subArr2];

    for (int i = 0; i < subArr1; i++)
        leftArr[i] = arr[i+1];
    for (int i = 0; i < subArr2; i++)
        rightArr[i] = arr[mid + 1 + i];

    auto idxSubArr1 = 0;
    auto idxSubArr2 = 0;
    int idxMergedArr = left;

    while (idxSubArr1 < subArr1 && idxSubArr2 < subArr2) {
        if (leftArr[idxSubArr1] <= rightArr[idxSubArr2]) {
            arr[idxMergedArr] = leftArr[idxSubArr1];
            idxSubArr1++;
        }
        else {
            arr[idxMergedArr] = rightArr[idxSubArr2];
            idxSubArr2++;
        }
        idxMergedArr++;
    }

    while (idxSubArr1 < subArr1) {
        arr[idxMergedArr] = leftArr[idxSubArr1]; 
        idxMergedArr++;
        idxSubArr1++;
    }

    while (idxSubArr2 < subArr2) {
        arr[idxMergedArr] = rightArr[idxSubArr2];
        idxMergedArr++;
        idxSubArr2++;
    }
}


void mergeSort(int arr[], int begin, int end) {

    if (begin >= end)
        return;

    auto mid = l + (r-1)/2;

    mergeSort(arr, begin, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, begin, end, mid);


}