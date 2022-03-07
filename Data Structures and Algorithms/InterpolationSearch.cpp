#include <iostream>

using namespace std;

int calcProbePos(int x, int arr[], int hi, int lo) {
    int pos = [(x-arr[lo])*(hi-lo)/arr[hi]-arr[lo]];
    return pos;
}

void interpolationSearch(int x, int arr[], int hi, int lo) {
    int n = sizeof(arr)/sizeof(arr[0]);
    //in a loop, calc pos
    for (;;) {
        int pos = calcProbePos(x, arr, hi, lo);
        //if match, return & exit
        if (x == pos)
            return pos;
        if (x > arr[pos])
            return interpolationSearch(x, arr, hi, x);
        if (arr[pos] > x)
            return interpolationSearch(x, arr, pos-1, lo);
    }
}