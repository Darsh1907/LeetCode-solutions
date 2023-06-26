#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=0; i<(nums.size()-1); i){
            if(nums[i]==nums[i+1]) nums.erase(nums.begin()+(i+1));
            else i++;
        }
        return nums.size();
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