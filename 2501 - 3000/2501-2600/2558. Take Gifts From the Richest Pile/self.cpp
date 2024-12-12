class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Max-heap priority queue (priority_queue by default is a max-heap in C++)
        priority_queue<int> pq;
        // Insert all the gift piles into the priority queue
        for (int gift : gifts) pq.push(gift);
        // We need to track the number of gifts left after k seconds
        long long totalRemainingGifts = 0;
        // Process for k seconds
        while (k--) {
            // Get the pile with the maximum number of gifts
            int top = pq.top();
            pq.pop();
            // Calculate the number of gifts that remain in this pile
            int leave_behind = sqrt(top);
            // Update the number of gifts remaining after this pile is reduced
            pq.push(leave_behind);
        }
        // After all operations, compute the total number of remaining gifts
        while (!pq.empty()) {
            totalRemainingGifts += pq.top();
            pq.pop();
        }
        return totalRemainingGifts;
    }
};