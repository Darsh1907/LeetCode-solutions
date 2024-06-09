// Refer: https://www.youtube.com/watch?v=bcXy-T4Sc3E

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> umap; // map to store remainder and index position
        umap[0] = 1;// this handles cases where the subarray starts from index 0
        int curr_sum = 0;
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            curr_sum += nums[i];
            int rem = curr_sum % k;
            if(rem < 0) rem += k; // ensure the remainder is non-negative
            if(umap.find(rem) != umap.end()) res += umap[rem];
            umap[rem]++;
        }
        return res;
    }
};