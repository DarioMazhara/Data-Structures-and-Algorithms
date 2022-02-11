//
//  JumpSearch.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/10/22.
//

#include <stdio.h>
#include <iostream>


#include <math.h>

using namespace std;

class JumpSearch {
    
public:
    
    int jumpSearch(int arr[], int size, int x) {
        
        int jump = sqrt(size);
        
        int prev = 0-jump;
        
        for (int i = 0; i < size; i+=jump) {
            if (prev >= size)
                return -1;
            if (arr[i] > x) {
                break;
            }
            prev += jump;
        }
        
        while (prev < (prev+jump)) {
            if (arr[prev] == x) {
                return prev;
            }
            prev++;
        }
        
        return -1;
    }
};

int main() {
    
     int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                   34, 55, 89, 144, 233, 377, 610 };
       int x = 2;
       int n = sizeof(arr) / sizeof(arr[0]);
        
    JumpSearch js;
       // Find the index of 'x' using Jump Search
       int index = js.jumpSearch(arr, n, x);
    
       // Print the index where 'x' is located
    cout << "\nNumber " << x << " is at index " << index << endl;
       return 0;
}
