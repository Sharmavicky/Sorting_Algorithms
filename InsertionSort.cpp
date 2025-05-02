#include <iostream>
#include <vector>
using namespace std;

/*
    takes an elements and places it in the correct position in the sorted part of the array.
    time complexity: O(N^2)
    space complexity: O(1)
*/

void InsertionSort(vector<int>& arr, int n) {
    for (int i=0; i<=n-1; i++) {
        int j = i;
        while (j>0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]); // swap the elements
            j--;
        }
    }
};


// Main function
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    InsertionSort(arr, n);

    // Print the sorted array
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}