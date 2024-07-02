class node {
public:
    int data;
    int row;
    int col;
    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        // two variables to keep track of the minimum and maximum values in the heap
        int minval = INT_MAX;
        int maxval = INT_MIN;
        priority_queue<node*, vector<node*>, compare> minHeap;
        // Populate the list with one element of every list.
        for(int i=0; i<k; i++) {
            maxval = max(nums[i][0], maxval);
            node* toAdd = new node(nums[i][0], i, 0);
            minHeap.push(toAdd);
        }
        minval = minHeap.top()->data;
        int start = minval, end = maxval;
        while(1) {
            node* temp = minHeap.top();
            minHeap.pop();
            // check if the array from which the old element is discarded and new element is added, has a next element (the array could have been exhausted)
            if(temp->col < nums[temp->row].size()-1) {
                node* toAdd = new node(nums[temp->row][temp->col + 1], temp->row, temp->col+1);
                maxval = max(maxval, toAdd->data);
                minHeap.push(toAdd);
                minval = minHeap.top()->data;
                // check if the new range is smaller than the previous range. Updatr if it is.
                if(maxval-minval < end-start) {
                    start = minval;
                    end = maxval;
                }
            }
            // if any array is exhausted, break the loop and return the minimum range yet discovered.
            else return {start, end};
        }
        return {};
    }
};