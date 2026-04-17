#include <iostream>
using namespace std;

class Heap {
private:
    int *arr;       // Array to store heap elements
    int capacity;   // Maximum size of the heap
    int size;       // Current number of elements in the heap

public:
    // Constructor to initialize heap
    Heap(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Destructor to release memory
    ~Heap() {
        delete[] arr;
    }

    // Utility function to swap two elements
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

    // Insert a new element into the heap
    void insert(int value) {
        if (size == capacity) {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }

        // Insert the new element at the end of the array
        int i = size;
        arr[i] = value;
        size++;

        // Adjust the heap by bubbling up the new element
        while (i > 0 && arr[i] > arr[(i - 1) / 2]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Delete the root (maximum) element from the heap
    int deleteRoot() {
        if (size <= 0) {
            cout << "Heap is empty. Nothing to delete." << endl;
            return -1;
        }

        int maxElement = arr[0];  // Store the root element
        arr[0] = arr[size - 1];   // Replace root with the last element
        size--;                   // Decrease the size of the heap

        // Restore the max-heap property by bubbling down
        heapify(0);

        return maxElement;
    }

    // Heapify function to maintain max-heap property
    void heapify(int i) {
        int largest = i;       // Initialize largest as root
        int left = 2 * i + 1;  // Left child
        int right = 2 * i + 2; // Right child

        // Check if left child is larger than root
        if (left < size && arr[left] > arr[largest]) {
            largest = left;
        }

        // Check if right child is larger than the current largest
        if (right < size && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not the root, swap and continue heapifying
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    // Build a heap from an existing array
    void buildHeap() {
        for (int i = (size / 2) - 1; i >= 0; i--) {
            heapify(i);
        }
    }

    // Perform heap sort and display sorted elements
    void heapSort() {
        // Build the heap from the array
        buildHeap();

        // Extract elements from the heap one by one
        for (int i = size - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);  // Move current root to the end
            size--;                // Reduce the size of the heap
            heapify(0);            // Heapify the reduced heap
        }

        // Display the sorted array
        cout << "Sorted elements: ";
        for (int i = 0; i < capacity; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Display the heap elements
    void display() {
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the size of the heap: ";
    cin >> n;

    Heap h(n);

    // Insert elements into the heap
    cout << "Enter " << n << " elements to insert: ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        h.insert(value);
    }

    h.display();

    // Delete the root element
    cout << "Deleted root element: " << h.deleteRoot() << endl;
    h.display();

    // Perform heap sort
    h.heapSort();

    return 0;
}
