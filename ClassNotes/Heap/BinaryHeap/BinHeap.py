def insertMaHeap (heap, value):
    heap.append(value)
    index = len(heap) - 1
    parent = index // 2
    while index > 1 and heap[index] > heap[parent]:
        # swap new element with its parent if it violets heap property
        heap[index], heap[parent] = heap[parent], heap[index]
        index = parent
        parent = index // 2
        
def heapify_max (arr):
    # start from the last parent node and work backwords
    for i in range(len(arr) // 2, 0, -1):
        _heapify_max(arr, i)
        
def _heapify_max(arr, i):
    #get indices of left and right children
    left = 2 * i
    right = 2 * i + 1
    
    # assume parent is the maximum value
    largest = i
    
    # check is left child is larger than parent
    if left <= len(arr) - 1 and arr[left] > arr[largest]:
        largest = left
        
    # check if right child is larger than parent
    if right <= len(arr) - 1 and arr[right] > arr[largest]:
        largest = right
        
    # if either child is larger, swap with parent amd recursively heapify
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        _heapify_max(arr, largest)
        

    