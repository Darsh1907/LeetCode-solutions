#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int atMostK(vector<int>& nums, int k){
        int l=0, r=0;
        unordered_map<int, int> umap;
        int count = 0;
        while(r < nums.size()) {
            umap[nums[r]]++;
            while(umap.size()>k){
                umap[nums[l]]--;
                if(umap[nums[l]] == 0) umap.erase(nums[l]);
                l++;
            }
            count = count + r - l + 1;
            r++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k-1);
    }
};


int main() {
    // Test the Solution class
    Solution solution;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    int result = solution.subarraysWithKDistinct(nums, k);
    cout << "Number of subarrays with " << k << " distinct integers: " << result << endl;
    return 0;
}