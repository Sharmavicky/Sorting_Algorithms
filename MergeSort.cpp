#include <iostream>
#include <vector>
using namespace std;


/*
    Time complexity: O(NlogN);
    Space complexity: O(N);
*/

void MergeArr(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp; // temporary array to store merged elements
    int left = low;
    int right = mid+1;

    // merge the two halves into a temporary array
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    };

    // copy remaining elements from the left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    };

    // copy remaining elements from the right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    };

    // replace the original array with the sorted elements.
    for (int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    };
};

void MergeSort(vector<int>& arr, int low, int high) {
    if (low >= high) return; // Base case

    int mid = (low + high) / 2; // find the middle index
    MergeSort(arr, low, mid); // left half
    MergeSort(arr, mid+1, high); // right half
    MergeArr(arr, low, mid, high); // merge the two halves;
};


// Main function
int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    MergeSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for (int i=0; i<n; i++) {
        cout << arr[i] << ", ";
    }

    return 0;
}