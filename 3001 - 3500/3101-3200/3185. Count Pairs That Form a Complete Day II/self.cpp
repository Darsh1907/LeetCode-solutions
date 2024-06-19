class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long count = 0;
        unordered_map<int, long long> umap; // remainder -> frequency of that remainder
        for(int i=0; i<hours.size(); i++) {
            int rem = hours[i]%24;
            count += umap[(24-rem)%24];
            umap[rem]++;
        }
        return count;
    }
};