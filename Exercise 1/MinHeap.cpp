#include "MinHeap.h"

// Constructor
MinHeap::MinHeap(int cap) {
    capacity = cap;
    heap_size = 0;
    harr = new int[cap];
}

// Destructor to free memory
//MinHeap::~MinHeap() {
//    delete[] harr;
//}

// To heapify a subtree with the root at given index
void MinHeap::MinHeapify(int index) {
    int smallest = index;
    int leftIndex = left(index);
    int rightIndex = right(index);

    if (leftIndex < heap_size && harr[leftIndex] < harr[smallest]) {
        smallest = leftIndex;
    }

    if (rightIndex < heap_size && harr[rightIndex] < harr[smallest]) {
        smallest = rightIndex;
    }

    if (smallest != index) {
        swap(&harr[index], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// To get index of parent of node
int MinHeap::parent(int index) {
    return (index - 1) / 2;
}

// To get index of left child of node
int MinHeap::left(int index) {
    return 2 * index + 1;
}

// To get index of right child of node
int MinHeap::right(int index) {
    return 2 * index + 2;
}

// Extract the root which is the minimum element
int MinHeap::extractMin() {
    if (heap_size <= 0) {
        throw out_of_range("Heap is empty");
    }

    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];

    // Replace root with last element and reduce size
    harr[0] = harr[heap_size - 1];

    heap_size--;

    MinHeapify(0); // Restore min-heap property

    return root;
}

// Returns the minimum key (key at root) from min heap
int MinHeap::getMin() {
    if (heap_size <= 0) {
        throw out_of_range("Heap is empty");
    }

    return harr[0];
}

// Deletes a key at index i
void MinHeap::deleteKey(int index) {
    if (index < 0 || index >= heap_size) {
        throw out_of_range("Index out of bounds");
    }

    decreaseKey(index, INT_MIN); // Decrease key to minimum value

    extractMin(); // Remove the minimum element (which is now the deleted element)
}

// Inserts a new key
void MinHeap::insertKey(int key) {
    if (heap_size == capacity) {
        throw overflow_error("Heap is full");
    }

    // Insert the new key at the end and increase size
    heap_size++;
    int i = heap_size - 1;
    harr[i] = key;

    // Fix the min-heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Utility function to swap two elements
void MinHeap::swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to decrease key value at index i to new_val
void MinHeap::decreaseKey(int i, int new_val) {
    if (i < 0 || i >= heap_size) {
        throw out_of_range("Index out of bounds");
    }

    harr[i] = new_val;

    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

