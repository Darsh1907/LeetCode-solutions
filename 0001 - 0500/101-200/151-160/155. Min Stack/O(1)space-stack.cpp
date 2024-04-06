// Node: This code wont work in LeetCode because 2*val does not fit into integer data type

class MinStack {
public:
    stack<int> s;
    int mini;

    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        // for first elemet
        if(s.empty()) {
            s.push(val);
            mini = val;
        }
        else {
            if(val < mini) {
                s.push(2*val-mini);
                mini = val;
            }
            else s.push(val);
        }
    }
    
    void pop() {
        if(s.empty()) return;
        int curr = s.top();
        s.pop();
        if(curr <= mini) mini = 2*mini - curr;
    }
    
    int top() {
        if(s.empty()) return -1;
        int curr = s.top();
        if(curr < mini) return mini;
        return curr;
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */