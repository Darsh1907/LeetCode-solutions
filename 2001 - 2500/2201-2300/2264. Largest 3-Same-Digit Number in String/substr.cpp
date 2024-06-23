class Solution {
public:
    string largestGoodInteger(string num) {
        string res = "";
        // Traverse through the string and look for three consecutive identical digits
        for (int i = 0; i <= num.size() - 3; ++i) {
            if (num[i] == num[i + 1] && num[i + 2] == num[i]) {
                // If we find such a triplet, we compare it with the current result
                string candidate = num.substr(i, 3);
                if (candidate > res) res = candidate;
            }
        }
        return res;
    }
};