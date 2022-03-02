#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX 1000

bool has[MAX+1][2];

bool search(int x) {
    if (x>=0) {
        if (has[x][0]==1)
            return true;
        else
            return false;
    }

    x = abs(x);
    if (has[x][1]==1)
        return true;
    return false;
    
}

void insert(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if(arr[i]>=0)
            has[arr[i]][0] = 1;
        else
            has[abs(arr[i])][1] = 1;
    }
}

int main() {
    int arr[] = {-1,9,-5,-8,-5,-2};
    int n = sizeof(arr)/sizeof(arr[0]);

    insert(arr, n);

    int x = 0;
    search(x) ? cout << "Present\n" : cout << "Not present\n";
    return 0;
}