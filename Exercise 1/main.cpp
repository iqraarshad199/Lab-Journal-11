#include "MinHeap.h"

void validateMinHeap() {
    MinHeap minHeap(10); // Create a MinHeap with capacity 10

    // Insert values into the min-heap: {3, 1, 6, 5, 2, 4}
    minHeap.insertKey(3);
    minHeap.insertKey(1);
    minHeap.insertKey(6);
    minHeap.insertKey(5);
    minHeap.insertKey(2);
    minHeap.insertKey(4);

    cout << "\n\tMinimum element: " << minHeap.getMin() << endl; // Should print 1

    cout << "\tExtracting minimum element: " << minHeap.extractMin() << endl; // Should print and remove 1

    cout << "\tNew minimum after extraction: " << minHeap.getMin() << endl; // Should print new minimum after extraction

    cout << "\tDeleting element '2'." << endl;

    // Find and delete '2'
    for (int i = 0; i < minHeap.heap_size; ++i) {
        if (minHeap.harr[i] == 2) {
            minHeap.deleteKey(i);
            break;
        }
    }

    cout << "\tNew minimum after deletion: " << minHeap.getMin() << endl;
}

int main() {
    validateMinHeap();
    return 0;
}
