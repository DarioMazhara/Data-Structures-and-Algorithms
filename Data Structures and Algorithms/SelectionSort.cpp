#include <iostream>
#include <vector>

using namespace std;


void swap(int* xp, int* yp) {
    int* temp = *xp;
    *xp = *yp;
    *yp = *temp;
}

void selectionSort(int arr[], int n) {

    int m_index;
    int i;
    int j;
    for (int i = 1; i < n-1; i++) {
        m_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[m_index]) {
                m_index = j;
            }
        }
        swap (&arr[m_index], &arr[j])

    }

}
void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};

    selectionSort(arr, (sizeof(arr)/sizeof(arr[0])));

 //   print(arr, (sizeof(arr)/sizeof(arr[0])));
}