#include "heapSort.h"


/**
 * Given an array a[], build a max heap by calling maxHeapify on each parent 
 * starting from the last non-leaf node(at n/2 - 1 th index) down to the root node(at 0th index).
 * Return a heap structure pointing to the same array a[], with size n.
 */
Heap buildMaxHeap(int *const a, int n)
{
    Heap h;
    h.a = a;
    h.size = n;

    for(int i = (n/2 - 1); i >= 0; --i)
        maxHeapify(h, i);
    return h;
}


/**
 * MAX_HEAPIFY: Compare h.a[idx] with its two children(if they exist), 
 * and swap the smallest of the three with the element at idx, 
 * and recursively call maxHeapify on the child node that got swapped.
 */
void maxHeapify(Heap h, int idx)
{
    int x, parent, right, left;
    parent = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if(left < h.size && h.a[left] > h.a[parent])
        parent = left;

    if(right < h.size && h.a[right] > h.a[parent])
        parent = right;
    
    if(h.a[parent] > h.a[idx])
    {
        x = h.a[parent];
        h.a[parent] = h.a[idx];
        h.a[idx] = x;    
        maxHeapify(h, parent);
    }
}


/**
 * HEAP_SORT: Sort array a[] by first building max heap, 
 * and then, iteratively swap the max element with last element
 * and call heapify on the root node. Remember to decrease heap.size after each iteration.
 */
void heapSort(int *const a, int n)
{
    Heap h = buildMaxHeap(a, n);
    for(int i = n - 1; i >= 0; --i) 
    {
        int parent = h.a[0];
        h.a[0] = h.a[i];
        h.a[i] = parent;
        h.size -= 1;
        maxHeapify(h, 0);
    }
}
