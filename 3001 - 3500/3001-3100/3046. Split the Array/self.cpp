class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_set<int> nums1;
        unordered_set<int> nums2;
        for(int i=0; i<nums.size(); i++) {
            if(nums1.find(nums[i]) != nums1.end()) {
                if(nums2.find(nums[i]) != nums2.end()) return false;
                else nums2.insert(nums[i]);
            }
            else nums1.insert(nums[i]);
        }
        return true;
    }
};

int main() {
    // Test the isPossibleToSplit function
    std::vector<int> nums = {1, 2, 3, 4, 5};
    Solution solution;
    bool result = solution.isPossibleToSplit(nums);
    std::cout << "Is it possible to split the array? " << (result ? "Yes" : "No") << std::endl;
    return 0;
}
