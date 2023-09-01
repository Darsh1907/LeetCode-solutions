class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        int i=0;
        vector<int> result;
        int n;
        int count = 0;
        while(i<length)
        {
            n=nums[i];
            result.push_back(n);
            count = 0;
            while(i!=nums.size()-1 && nums[i]==nums[i+1])
            {
                count++;
                if(count<=1){
                    result.push_back(n);
                    i++;
                }
                else i++;
            }
            i++;
        }
        nums.clear();
        nums = result;
        return result.size();
    }
};