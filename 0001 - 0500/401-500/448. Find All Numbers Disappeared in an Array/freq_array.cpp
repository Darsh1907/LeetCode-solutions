class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        vector<bool> freq(size, false);
        for(int i=0; i<size; i++){
            freq[nums[i]-1] = true;
        }
        vector<int> result;
        for(int i=0; i<size; i++){
            if(freq[i]==false) result.push_back(i+1);
        }
        return result;
    }
};