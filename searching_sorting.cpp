#include <iostream>
using namespace std;

// --- HELPER FUNCTION: To print the array ---
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ==========================================
// PART 1: SEARCHING ALGORITHMS
// ==========================================

// 1. Linear Search (Works on Unsorted Data)
// Time Complexity: O(n)
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// 2. Binary Search (Requires SORTED Data)
// Time Complexity: O(log n)
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // Found it
        
        if (arr[mid] < target)
            left = mid + 1; // Look in right half
        else
            right = mid - 1; // Look in left half
    }
    return -1; // Not found
}

// ==========================================
// PART 2: SORTING ALGORITHMS
// ==========================================

// 3. Bubble Sort (Swaps neighbors)
// Time Complexity: O(n^2)
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 4. Selection Sort (Finds minimum and places it)
// Time Complexity: O(n^2)
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        // Find the smallest element in the remaining unsorted array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum with the first element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// 5. Insertion Sort (Like sorting cards)
// Time Complexity: O(n^2)
void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key one step ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ==========================================
// MAIN FUNCTION TO TEST EVERYTHING
// ==========================================
int main() {
    // Test Data
    int data[] = {64, 25, 12, 22, 11};
    int n = 5;
    
    // We make copies so we can test different sorts on the same original data
    int arr1[] = {64, 25, 12, 22, 11}; 
    int arr2[] = {64, 25, 12, 22, 11};
    int arr3[] = {64, 25, 12, 22, 11};

    cout << "--- SEARCHING ---" << endl;
    
    // 1. Test Linear Search (Data is unsorted, so we MUST use Linear)
    int target = 12;
    int result = linearSearch(data, n, target);
    if(result != -1) cout << "Linear Search: Found 12 at index " << result << endl;
    else cout << "Linear Search: Not found" << endl;


    cout << "\n--- SORTING ---" << endl;

    // 2. Test Bubble Sort
    bubbleSort(arr1, n);
    cout << "Bubble Sorted:    ";
    printArray(arr1, n);

    // 3. Test Selection Sort
    selectionSort(arr2, n);
    cout << "Selection Sorted: ";
    printArray(arr2, n);

    // 4. Test Insertion Sort
    insertionSort(arr3, n);
    cout << "Insertion Sorted: ";
    printArray(arr3, n);


    cout << "\n--- BINARY SEARCH (Requires Sorted Array) ---" << endl;
    
    // Now that arr1 is sorted, we can use Binary Search
    target = 25;
    result = binarySearch(arr1, n, target);
    if(result != -1) cout << "Binary Search: Found 25 at index " << result << endl;
    else cout << "Binary Search: Not found" << endl;

    return 0;
}
