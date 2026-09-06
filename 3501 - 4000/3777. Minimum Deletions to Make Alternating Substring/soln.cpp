class Solution {
public:
    struct RangeSumTree {
        int n;
        vector<int> bit;
        RangeSumTree(int size) {
            n = size;
            bit = vector<int>(n + 1, 0);
        }
        void update(int i, int delta) {
            for (i++; i <= n; i += i & -i) bit[i] += delta;
        }
        int query(int i) {
            int sum = 0;
            for (i++; i>0; i -= i & -i) sum += bit[i];
            return sum;
        }
        int rangeQuery(int l, int r) {
            if (l > r) return 0;
            int rquery = query(r);
            int lquery = 0;
            if(l>0) lquery = query(l-1);
            return rquery - lquery;
        }
    };
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        RangeSumTree rst(n-1);
        for (int i = 0; i+1 < n; i++) { // build adjacency array
            if (s[i] == s[i + 1]) rst.update(i, 1);
        }
        vector<int> answer;
        for (auto &q : queries) {
            if (q[0] == 1) {
                int j = q[1];
                // remove old contributions
                if (j>0) {
                    if (s[j-1] == s[j]) rst.update(j-1, -1);
                }
                if (j < n-1) {
                    if (s[j] == s[j+1]) rst.update(j, -1);
                }
                // flip character
                s[j] = (s[j] == 'A') ? 'B' : 'A';
                // add new contributions
                if(j>0) {
                    if (s[j-1] == s[j]) rst.update(j-1, 1);
                }
                if(j < n-1) {
                    if (s[j] == s[j+1]) rst.update(j, 1);
                }
            }
            else {
                int l = q[1], r = q[2];
                answer.push_back(rst.rangeQuery(l, r-1));
            }
        }
        return answer;
    }
};