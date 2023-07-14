// Note: This code gave Time Limit Exceeded and hence has higher complexity than required.

class Solution {
public:

    int isin(vector<int>&temp, vector<vector<int>>&result){
        for(int i=0; i<result.size(); i++)
            if(result[i]==temp) return 1;
        return 0;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int max = nums[nums.size()-1];
        int sum;
        int req;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                sum = nums[i]+nums[j];
                req = -1*sum;
                if(req<nums[j] || req>max);
                else{
                    for(int k=j+1; k<nums.size(); k++){
                        if(nums[k]==req){
                            temp.clear();
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[k]);
                            int flag = isin(temp, result);
                            if(flag==0) result.push_back(temp);
                        }
                    }
                }
            }
        }
        return result;
    }
};