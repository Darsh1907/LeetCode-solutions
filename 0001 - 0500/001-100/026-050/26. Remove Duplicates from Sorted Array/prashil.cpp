#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        int i=0;
        vector<int> result;
        int n;
        while(i<length)
        {
            n=nums[i];
            result.push_back(n);
            while(i!=nums.size()-1 && nums[i]==nums[i+1])
            {
                i++;
            }
            i++;
        }
        nums.clear();
        nums = result;
        return result.size();
    }
};

int main() {
    // Example usage
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution solution;
    int length = solution.removeDuplicates(nums);
    cout << "New length: " << length << endl;
    cout << "Modified array: ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}