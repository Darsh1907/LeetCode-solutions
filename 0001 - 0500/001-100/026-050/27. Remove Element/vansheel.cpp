class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        vector<int> temp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=val) temp.push_back(nums[i]);
            else count++;
        }
        int result = temp.size();
        while(count){
            temp.push_back(-1);
            count--;
        }
        nums.clear();
        nums = temp;
        return result;
    }
};