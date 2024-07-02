# include<queue>

using namespace std;

// Logic is that we will keep two heaps. A max heap (for the left side elements) and a min heap (for the right side elements)

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }
        if(num <= maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);
        // Balance the heaps so that their sizes differ by at most 1
        if (maxHeap.size() > minHeap.size()+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) return ((double)maxHeap.top() + (double)minHeap.top()) / 2;
        else return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
*/