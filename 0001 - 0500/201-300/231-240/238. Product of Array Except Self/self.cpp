// Brute Force: O(n^2)
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int> result(nums.size());
//         fill(result.begin(), result.end(), 1);
//         for(int i=0; i<nums.size(); i++){
//             for(int j=0; j<nums.size(); j++){
//                 if(j==i);
//                 else result[j] = result[j] * nums[i];
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1; // normal product
        int prod_wido_0 = 1; // product without 1 zero
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                product = product * nums[i];
                prod_wido_0 = prod_wido_0 * nums[i];
            }
            else if(nums[i]==0 && product!=0){
                product = 0;
            }
            else if(nums[i]==0 && product==0){
                prod_wido_0 = 0;
                break;
            }
        }
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) result.push_back(prod_wido_0);
            else result.push_back(product/nums[i]);
        }
        return result;
    }
};