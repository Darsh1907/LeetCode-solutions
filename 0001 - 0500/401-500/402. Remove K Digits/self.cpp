// Reference:
// https://www.youtube.com/watch?v=3QJzHqNAEXs

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        // If you must have to delete all the elements.
        if(num.size()==k) return "0";
        // Stack to store the elements such that the eradicate all the "dips" (Try to the select numbers in ascending order as much as possible)
        stack<char> st;
        for(int i=0; i<num.size(); i++) {
            // If you get a dip, then remove the top element from the stack. Repeat until the dip is removed.
            // Make sure you remove from stack if u have more elements to remove, Otherwise just add the remaining elements to the stack.
            while(k>0 && !st.empty() && st.top()>num[i]) {
                st.pop();
                k--;
            }
            // Push the new element to the stack.
            st.push(num[i]);
        }
        // If you have to remove more elements, then remove from the top of the stack.
        while(k) {
            st.pop();
            k--;
        }
        // Form the result from the stack.
        string result;
        while(!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        // Reverse the result and remove the leading zeros.
        reverse(result.begin(), result.end());
        // Removing the leading zeros.
        int i=0;
        while(result[i]=='0') i++;
        result = result.substr(i, result.size()-i);
        // If the result is empty, then return "0".
        if(result.empty()) return "0";
        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    string num1 = "1432219";
    int k1 = 3;
    string output1 = solution.removeKdigits(num1, k1);
    cout << "Output 1: " << output1 << endl;
    
    // Test case 2
    string num2 = "10200";
    int k2 = 1;
    string output2 = solution.removeKdigits(num2, k2);
    cout << "Output 2: " << output2 << endl;
    
    // Test case 3
    string num3 = "10";
    int k3 = 2;
    string output3 = solution.removeKdigits(num3, k3);
    cout << "Output 3: " << output3 << endl;
    
    // Test case 4
    string num4 = "9";
    int k4 = 1;
    string output4 = solution.removeKdigits(num4, k4);
    cout << "Output 4: " << output4 << endl;
    
    // Test case 5
    string num5 = "112";
    int k5 = 1;
    string output5 = solution.removeKdigits(num5, k5);
    cout << "Output 5: " << output5 << endl;
    
    // Test case 6
    string num6 = "10001";
    int k6 = 4;
    string output6 = solution.removeKdigits(num6, k6);
    cout << "Output 6: " << output6 << endl;
    
    return 0;
}