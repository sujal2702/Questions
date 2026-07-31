// Function to Heapify the exisiting array in heap 

void heapify(vector<int>& arr, int i, int n) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

//Build the Maxheap 

void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();

    // Start from the last non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }
}
//Since from n/2 to n all the nodes are leaf node so they have no children from which we can compare them whether they are big or not
