#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        return nums.size();
    }
};

int main() {
    // Example usage
    vector<int> nums = {3, 2, 2, 3, 1, 4, 2, 3};
    int val = 2;

    // Solution should be {3, 3, 1, 4, 3}
    
    Solution solution;
    int length = solution.removeElement(nums, val);
    
    cout << "New length: " << length << endl;
    cout << "Modified array: ";
    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}
