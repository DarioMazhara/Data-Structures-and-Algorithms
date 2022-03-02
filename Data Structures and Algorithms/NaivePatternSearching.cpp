//
//  NaivePatternSearching.cpp
//  Data Structures and Algorithms
//
//  Created by Dario Mazhara on 2/12/22.
//

#include <stdio.h>
#include <iostream>

using namespace std;
class NaivePatternSearch {
public:
    
    
    void search(char* pat, char* txt) {
        int M = strlen(pat);
        int N = strlen(txt);
        
        for (int i = 0; i < N - M; i++) {
            int j;
            
            for (j = 0; j < M; j++) {
                if (txt[i+j] != pat[j])
                    break;
            }
            
            if (j == M)
                cout << "Pattern found at index: " << i << endl;
        }
    }
    
    void optimizedSearch(string pat, string txt) {
        int M = pat.size();
        int N = txt.size();
        
        int i = 0;
        
        while (i <= N - M) {
            int j;
            
            for (j = 0; j < M; j++) {
                if (txt[i+j] != pat[j]){
                    break;
                }
            }
            
            if (j == M) {
                cout << "Pattern: " << i << endl;
                i += M;
            }
            else if (j == 0) {
                i+=1;
            }
            else {
                i+=j;
            }
        }
    }
};

int main() {
    
    
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    
    NaivePatternSearch* nps = new NaivePatternSearch();
    
    nps->search(pat, txt);
}
