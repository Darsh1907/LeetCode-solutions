class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int smallest = INT_MAX, secSmallest = INT_MAX, largest = INT_MIN, secLargest = INT_MIN;
        for (auto i : nums) {
            if (i < smallest) {
                secSmallest = smallest;
                smallest = i;
            }
            else if (i < secSmallest) secSmallest = i;
            if (i > largest) {
                secLargest = largest;
                largest = i;
            }
            else if (i > secLargest) secLargest = i;
        }
        return largest*secLargest - smallest*secSmallest;
    }
};