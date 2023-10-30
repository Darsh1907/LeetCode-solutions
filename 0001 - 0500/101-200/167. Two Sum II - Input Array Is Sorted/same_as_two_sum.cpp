class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // This is same solution as that of LeetCode-Two Sum
        // Better solution than this does exist
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++){
            int complement = target - numbers[i];
            if(m.find(complement) != m.end()){
                result.push_back(m[complement]+1);
                result.push_back(i+1);
                return result;
            }
            else{
                m[numbers[i]] = i;
            }
        }
        return result;
    }
};