#include <iostream>
#include <vector>
using namespace std;

/*
    Time complexity: O(NlogN) where 'N' is the number of elements in the array
    Space complexity: O(1)
*/

int findPivot(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // pivot element
    int i=low, j=high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) { // finds the first element greater than pivot
            i++;
        };

        while (arr[j] > pivot && j > low) { // finds the first element smaller than pivot
            j--;
        };

        if (i < j) { // swaps both elements until 'i' crosses 'j' or 'i' equals 'j'
            swap(arr[i], arr[j]);
        }
    };

    swap(arr[low], arr[j]); // places pivot element to it's correct place
    return j; // returns the correct index of pivot element
};

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p_idx = findPivot(arr, low, high); 
        quickSort(arr, low, p_idx-1); // passing left side of pivot (smaller than pivot)
        quickSort(arr, p_idx+1, high); // passing right side of pivot (greater than pivot)
    }
};


// Main Function
int main() {
    vector<int> arr = { 20, 13, 15, 76, 39, 0 };
    
    // calling quick sort
    quickSort(arr, 0, arr.size()-1);

    // printing sorted array
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << ", ";
    };

    return 0;
}