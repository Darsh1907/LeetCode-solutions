class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> result;
        int ans = 0;
        int num = 1;
        while(result.size()<n) {
            if(result.find(k-num) != result.end());
            else {
                // ans.push_back(num);
                result.insert(num);
                ans = ans + num;
            }
            num++;
        }
        return ans;
    }
};