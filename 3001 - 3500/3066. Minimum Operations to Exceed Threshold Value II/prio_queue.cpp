class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto it:nums) pq.push(it);
        while(pq.size()>1){
            long long v1 = pq.top();
            pq.pop();
            if(v1>=k) break;
            long long v2 = pq.top();
            pq.pop();
            pq.push(v1*2+v2);
            ans++;
        }
        return ans;
    }
};