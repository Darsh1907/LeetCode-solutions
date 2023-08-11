class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int non_zer_index = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                nums[non_zer_index] = nums[i];
                non_zer_index++;
            }
        }
        for(int i=non_zer_index; i<nums.size(); i++){
            nums[i]=0;
        }
    }
};