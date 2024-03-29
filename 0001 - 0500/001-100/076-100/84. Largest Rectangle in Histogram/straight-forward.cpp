class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=INT_MIN, n=heights.size();
        stack<pair<int,int>> st;
        st.push({heights[0],0});
        for(int i=1; i<n; i++) {
            int start = i;
            while(!st.empty() && heights[i]<=st.top().first) {
                start = st.top().second;
                ans = max(ans,(i-start)*st.top().first);
                st.pop();
            }
            st.push({heights[i],start});
        }
        while(!st.empty()) {
            ans = max(ans,(n-st.top().second)*st.top().first);
            st.pop();
        }
        return ans;
    }
};