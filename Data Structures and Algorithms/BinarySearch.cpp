//
//  BinarySearch.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/10/22.
//

#include <stdio.h>
#include <iostream>

using namespace std;

class BinarySearh {
public:
    
    //array must be sorted
    int binarySearch(int array[], int l, int r, int x) {
        
        while (l <= r) {
            int m = l + (r-1)/2;
            
            if (array[m] == x)
                return m;
            
            if (array[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        
        
        return -1;
    }
    
    int recursiveBinary(int array[], int l, int r, int x) {
        
        int m = l + (r-1) / 2;
        
        if (array[m] == x)
            return m;
        
        if (array[m] < x)
            return recursiveBinary(array, (m+1), r, x);
        
        return recursiveBinary(array, l, (m-1), x);
        
        return -1;
    }
    
    
};
