#include <iostream>
using namespace std;


/*
    Time Complexity: O(n^2);
    Space Complexity: O(1);
*/

void SelectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int minIdx = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]); // swap the found minimum element with the first element
    }

    // printing the sorted array
    cout << "Sorted array: ";
    for (int i=0; i<n; i++) {
        cout << arr[i] << ", ";
    };
};

// Main function
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    SelectionSort(arr, n);
    return 0;
}