#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
    }
};

int main() {
    // Example usage
    vector<int> nums = {3, 2, 2, 3, 1, 4, 2, 3};
    int val = 2;
    
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
