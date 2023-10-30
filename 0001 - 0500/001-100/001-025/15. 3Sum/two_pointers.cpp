class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        vector<vector<int>> result;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n - 2; i++) {
            if (i == 0 || (i > 0 && arr[i] != arr[i - 1])) { // Handle duplicates
                int l = i + 1;
                int r = n - 1;
                while (l < r) {
                    int sum = arr[i] + arr[l] + arr[r];
                    if (sum == 0) {
                        result.push_back({arr[i], arr[l], arr[r]});
                        while (l < r && arr[l] == arr[l + 1]) l++; // Handle duplicates
                        while (l < r && arr[r] == arr[r - 1]) r--; // Handle duplicates
                        l++;
                        r--;
                    } 
                    else if (sum < 0) l++;
                    else r--;
                }
            }
        }
        return result;        
    }
};