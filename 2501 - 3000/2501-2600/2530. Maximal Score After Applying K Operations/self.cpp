class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> maxH;
        // Insert all elements into the max heap
        for(int num : nums) maxH.push(num);
        // Perform k operations
        for(int i=0; i<k; i++) {
            int top = maxH.top();
            score += top;  // Add the top element to the score
            maxH.pop();    // Remove the top element
            // Push back the value after applying the operation using ceil
            maxH.push(static_cast<int>(ceil(static_cast<double>(top) / 3)));
        }
        return score;
    }
};