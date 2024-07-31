class Solution {
    int helper(int i, unordered_map<int, int>& cache, vector<vector<int>>& books, int shelfWidth) {
        if(i == books.size()) return 0; // if u reach out of bounds for the books array.
        // check if the result already exists in the dp
        auto inCache = cache.find(i);
        if(inCache != cache.end()) return inCache->second; // if it exists, then return the cached value
        int cur_width = shelfWidth; // cur_width will store the remaining width.
        int max_height = 0; // max height will store the maximum height in that shelf.
        cache[i] = INT_MAX;
        // Iterate on the next books. Place them in the same shelf or create a new shelf (using recursion) select the one that gives the minimum value.
        for (int j=i; j<books.size(); j++) {
            int width = books[j][0];
            int height = books[j][1];
            if(cur_width < width) break;
            cur_width -= width; // consume width of the new book
            max_height = max(max_height, height);
            auto cache_i = cache.find(i); // current value in cache[i]
            cache_i->second = min(cache_i->second, helper(j+1, cache, books, shelfWidth) + max_height); // new cache value will be minimum of already cached and the height we get if the next element was added to the new shelf + max_height of the curr_self.
        }
        return cache[i];
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // using DP
        unordered_map<int, int> cache;
        return helper(0, cache, books, shelfWidth);
    }
};