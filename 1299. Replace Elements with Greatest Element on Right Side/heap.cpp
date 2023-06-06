class Solution {
public:
    void heapify(vector<int>& heap, int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    vector<int> replaceElements(vector<int>& arr) {
        vector<int> heap;
        int n = arr.size();
        int temp;

        heap.push_back(arr[n - 1]);  // Add the last element to the heap
        arr[n-1] = -1;  // Replace the last element in arr with -1

        for (int i=n-2; i>=0; i--) {
            temp = arr[i];
            arr[i] = heap[0];  // Replace the current element in arr with the maximum element from the heap
            heap.push_back(temp);  // Add the current element to the heap
            heapify(heap, heap.size()-1);  // Heapify the heap
        }
        return arr;
    }
};