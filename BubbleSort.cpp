#include <iostream>
#include <vector>
using namespace std;

/*
    Time complexity: O(n^2); where n is the number of elements in the array.
    Space complexity: O(1); 
*/

void BubbleSort(vector<int>& arr, int n) {
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<=i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; // swap the elements if they are in wrong order
            }
        }
    }
};

// Main Function
int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    BubbleSort(arr, n); // sort the array

    cout << "Sorted array: \n";
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}