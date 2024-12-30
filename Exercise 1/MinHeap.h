#pragma once
#include<iostream>
#include <stdexcept>

using namespace std;

class MinHeap
{
public:
	int* harr; // pointer to array of elements in heap 
	int capacity; // maximum possible size of min heap 
	int heap_size; // Current number of elements in min heap 

	/**
	 * @Constructor to initialize a MinHeap with a given capacity.
	 * @cap The maximum number of elements that the heap can hold.
	 */
	MinHeap(int);
	
	/**
	 * @Heapifies a subtree with the root at the given index.
	 * This function ensures that the min-heap property is maintained.
	 * @index The index of the root node of the subtree to heapify.
	 */
	void MinHeapify(int);

	/**
	* @Gets the index of the parent of a node.
	* @index The index of the child node.
	* @return The index of the parent node.
	*/
	int parent(int);

	/**
	 * @Gets the index of the left child of a node.
	 * @index The index of the parent node.
	 * @return The index of the left child node.
	 */
	int left(int);

	/**
	* @Gets the index of the right child of a node.
	* @index The index of the parent node.
	* @return The index of the right child node.
	*/
	int right(int);

	/**
	 * @Extracts and returns the root (minimum element) from the min heap.
	 * This operation removes the minimum element and restores the min-heap property.
	 * @return The minimum element from the heap.
	 */
	int extractMin();

	/**
	 * @Returns the minimum key (key at root) from min heap without removing it.
	 * @return The minimum key from the heap.
	 */
	int getMin();

	/**
	 * @Deletes a key at a specified index in the heap.
	 * This operation first decreases the key to INT_MIN and then extracts it.
	 * @index The index of the key to be deleted.
	 */
	void deleteKey(int);

	/**
	* @Inserts a new key into the min heap while maintaining its properties.
	* @key The value to be inserted into the heap.
	*/
	void insertKey(int);

	/**
	* @Swaps two integer values in memory.
	* This utility function is used to exchange values between two nodes in the heap.
	* @x Pointer to an integer value to be swapped.
	* @y Pointer to another integer value to be swapped with x.
	*/
	void swap(int*, int*);

	/**
	 * @Decreases key value at a specified index to a new value.
	 * This function maintains min-heap properties after decreasing a key's value.
	 * @i The index of the key to decrease.
	 * @new_val The new value to set at that index, which must be smaller than
	 * its current value.
	 */
	void decreaseKey(int i, int new_val);

};

