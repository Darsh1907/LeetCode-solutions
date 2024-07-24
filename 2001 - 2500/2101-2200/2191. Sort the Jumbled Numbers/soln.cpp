class Solution {
    int translate_integer(vector<int>& mapping, int num) {
        string digits = to_string(num);
        for(char& digit : digits) digit = '0' + mapping[digit-'0'];
        return stoi(digits);
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, int> number_mapping;
        for(int num : nums) {
            if(number_mapping.find(num) == number_mapping.end()) {
                number_mapping[num] = translate_integer(mapping, num);
            }
        }
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return number_mapping[a] < number_mapping[b];
        });
        return nums;
    }
};