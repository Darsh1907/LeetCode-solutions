// References:
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// https://www.youtube.com/watch?v=9u2BJfmWNEg&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=62
// https://www.youtube.com/watch?v=lJLcqDsmYfg&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=62

class Solution {
private:
    vector<int> nextSmaller(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()]>=curr) s.pop();
            // ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()]>=curr) s.pop();
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), result=0;
        vector<int> next(n);
        vector<int> prev(n);
        next = nextSmaller(heights, n);
        prev = prevSmaller(heights, n);
        for(int i=0; i<n; i++) {
            int l = heights[i];
            if(next[i]==-1) next[i]=n;
            int b = next[i] - prev[i] - 1;
            int area = l*b;
            result = max(area, result);
        }
        return result;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // convert char matrix into int matrix
        vector<vector<int>> int_matrix(matrix.size(), vector<int>(matrix[0].size()));
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                int_matrix[i][j] = matrix[i][j]-'0';
            }
        }
        // compute area of first row
        int area = largestRectangleArea(int_matrix[0]);
        // from second row
        for(int i=1; i<int_matrix.size(); i++){
            for(int j=0; j<int_matrix[0].size(); j++){
                if(int_matrix[i][j]!=0) int_matrix[i][j] += int_matrix[i-1][j];
            }
            // entire row is updated
            area = max(area, largestRectangleArea(int_matrix[i]));
        }
        return area;
    }
};