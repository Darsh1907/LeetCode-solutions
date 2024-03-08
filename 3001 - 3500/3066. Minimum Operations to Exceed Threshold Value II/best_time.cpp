class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0]>=k) return 0;
        if(nums[1]>=k) return 1;
        vector<long long int> added;
        int top=0, ans=0, i=1;
        long long int sum=0, num1=nums[0], num2=nums[1];
        while(i<nums.size() && nums[i]<k) {
            if(i!=1){
                // decide num1 & num2
                if(top < added.size() && added[top]<nums[i]){
                    num1 = added[top++];
                    if(top < added.size() && added[top]<nums[i]) num2=added[top++];
                    else num2=nums[i++];
                }
                else {
                    num1 = nums[i++];
                    if(top < added.size()) {
                        if(i<nums.size() && added[top]<nums[i]) num2=added[top++];
                        else if (i<nums.size()) num2=nums[i++];
                        else num2=added[top++];
                    } 
                    else {
                        if(i<nums.size()) num2 = nums[i++];
                        else return ans+1;
                    }
                }
            }
            else i++;
            sum = num1*2 + num2;
            if(sum<k) added.push_back(sum);
            ans++;
        }
        while(top<added.size() && added[top]<k){
            num1=added[top];
            if(top+1==added.size() || added[top+1]>=k) return ans+1;
            num2 = added[top+1];
            sum = num1*2+num2;
            if(sum<k) added.push_back(sum);
            ans++;
            top+=2;
        }
        return ans;
    }
};