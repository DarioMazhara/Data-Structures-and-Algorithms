//
//  SuffixArray.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/12/22.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class SuffixArray {
public:
    struct suffix {
        int index;
        char* suff;
    }
    
    int cmp(struct suffix a, struct suffix b) {
        return strncmp(a.suff, b.suff) < 0 ? 1 : 0;
    }
    
    int *buildSuffixArray(char* txt, int n) {
        struct suffix suffixes[n];
        
        for (int i = 0; i < n; i++) {
            suffixes[i].index = i;
            suffixes[i].suff = (txt+i);
        }
        
        sort(suffixes, suffixes+n, cmp);
        
        int *suffixArr = new int[n];
        
        for (int i = 0; i < n; i++) {
            suffixArr[i] = suffixes[i].index;
        }
        
        return suffixArr;
        
    }
    void search(char *pat, char *txt, int *suffArr, int n) {
        int m = strlen(pat);
        
        int l = 0;
        int r = n-1;
        
        while (l <= r) {
            int mid = 1 + (r-1)/2;
            int res = strncmp(pat, txt+suffArr[mid], n);
            
            if (res == 0) {
                cout << "Pattern at index: " << suffArr[mid] << endl;
                return;
            }
            
            if (res < 0) r = mid-1;
            
            else l = mid+1;
        }
        cout << "Pattern not found" << endl;
    }
};

int main() {
    char txt[] = "banana";
    char pat[] = "nan";
    
    int n = strlen(txt);
}
