class Solution {
private:
    int greater_char(string s){
        int result = 0;
        for(int i=0; i<s.size(); i++){
            int ele = s[i] - '0';
            result = max(result , ele); 
        }
        return result;
    }
    void encrypt(int* num) {
        string s = to_string(*num);
        int greater = greater_char(s);
        string new_str;
        for(int i=0; i<s.size(); i++) new_str+=to_string(greater);
        *num = stoi(new_str);
        return;
    }
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<nums.size(); i++) encrypt(&nums[i]);
        for(int i=0; i<nums.size(); i++) ans+=nums[i];
        return ans;
    }
};