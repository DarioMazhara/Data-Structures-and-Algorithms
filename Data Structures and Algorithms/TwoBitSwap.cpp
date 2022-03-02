//
//  TwoBitSwap.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/12/22.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int swapBits(unsigned int n, unsigned int p1, unsigned int p2) {
    
    unsigned int bit1 = (n >> p1) & 1;
    unsigned int bit2 = (n >> p2) & 1;
    
    unsigned int x = (bit1 ^ bit2);
    
    x = (x << p1) | (x << p2);
    
    unsigned int result = n ^ x;
    return result;
}

int main() {
    int res = swapBits(28, 23, 9);
    
    cout << res << endl;
    return 0;
}
