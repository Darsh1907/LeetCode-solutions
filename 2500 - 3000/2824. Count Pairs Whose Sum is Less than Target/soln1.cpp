// Logic:
// After sorting the array, you pick an element and find all pairs that satisfy condition (from the next element)
// When the condition fails, you can pick another element because:
// Once, the sum>required_sum, the leftover elements will definetly generate a greater sum than the req_sum

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int count=0;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size();i++){
            for (int j=i+1;j<nums.size();j++){
                if (nums[i] + nums[j] < target){
                    count++;
                }
                else{
                    break;
                }
            }
        }
        return count;
    }
};