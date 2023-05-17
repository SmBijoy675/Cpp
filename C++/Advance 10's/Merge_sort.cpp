#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge two sorted subarrays
    int i = left;
    int j = mid + 1;
    int k = 0;
    vector<int> temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements from the first subarray
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements from the second subarray
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy the merged elements back to the original array
    for (int x = 0; x < temp.size(); x++) {
        arr[left + x] = temp[x];
    }
}

int main() {
    vector<int> arr = {7, 2, 5, 1, 9, 3, 6, 8, 4};
    int n = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
