#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void minHeapSort(int arr[], int n) {
    // Build Min Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);  // Move the smallest element to the end
        minHeapify(arr, i, 0); // Heapify the reduced heap
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    minHeapSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

