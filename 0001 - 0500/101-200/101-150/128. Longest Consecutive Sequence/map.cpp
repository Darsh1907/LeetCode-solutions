class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Step 1: Create an unordered map 'mp' to store whether a number is present in the input vector 'nums'.
        unordered_map<int, bool> mp;
        // Step 2: Iterate through the input vector and populate the unordered map with the presence of each number.
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]] = true;
        }
        // Step 3: Iterate through the input vector again:
        for(int i = 0; i < n; i++) {
            // If 'nums[i] - 1' is present in 'mp', mark 'nums[i]' as not the start of a consecutive sequence by setting its value in the map to false.
            if(mp.count(nums[i] - 1) > 0) mp[nums[i]] = false;
        }
        // Step 4: Find the length of the consecutive sequences starting from the marked points and update the maximum length.
        int ml = 0;
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]] == true) {
                int j = 0, c = 0;
                // Count the length of the consecutive sequence starting from 'nums[i]'.
                while(mp.count(nums[i] + j) > 0) {
                    j++;
                    c++;
                }
                // Update 'ml' if the length of the current sequence is greater.
                if(c > ml) ml = c;
            }
        }
        // Step 5: Return the length of the longest consecutive sequence.
        return ml;
    }
};