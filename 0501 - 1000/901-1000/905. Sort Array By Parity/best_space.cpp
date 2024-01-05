class Solution {
public:
    void swap(int& a, int& b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l=0;
        if(nums.size()==1) return nums;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                swap(nums[i],nums[l]);
                l++;
            }  
        }
        return nums;
    }
};