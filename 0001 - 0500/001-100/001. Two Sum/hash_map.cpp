#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            int complement = target - nums[i];
            if(m.find(complement) != m.end()) {
                result.push_back(m[complement]);
                result.push_back(i);
                return result;
            } 
            else m[nums[i]] = i;
        }
        return result;
    }
};

int main() {
    // Test case 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    Solution solution1;
    vector<int> result1 = solution1.twoSum(nums1, target1);
    if (result1.size() == 2) {
        cout << "Indices: " << result1[0] << ", " << result1[1] << endl;
        cout << "Values: " << nums1[result1[0]] << ", " << nums1[result1[1]] << endl;
    } else {
        cout << "No valid indices found." << endl;
    }

    // Test case 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    Solution solution2;
    vector<int> result2 = solution2.twoSum(nums2, target2);
    if (result2.size() == 2) {
        cout << "Indices: " << result2[0] << ", " << result2[1] << endl;
        cout << "Values: " << nums2[result2[0]] << ", " << nums2[result2[1]] << endl;
    } else {
        cout << "No valid indices found." << endl;
    }

    return 0;
}
