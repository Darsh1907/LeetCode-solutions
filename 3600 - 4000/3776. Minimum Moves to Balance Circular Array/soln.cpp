class Solution {
    int min(int a, int b) {
        if(a<b) return a;
        return b;
    }
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        long long total = 0;
        int negIdx = -1;
        for (int i = 0; i < n; i++) {
            total += balance[i];
            if (balance[i] < 0) negIdx = i;
        }
        if (negIdx == -1) return 0; // If no negative balance, no moves needed
        if (total < 0) return -1; // If total sum is negative, impossible
        long long need = -balance[negIdx];
        long long moves = 0;
        for(int i=1; i<=n/2 && need>0; i++) {
            int left = (negIdx-i+n)%n;
            int right = (negIdx+i)%n;
            if(balance[left]) {
                long long take = min(balance[left], need);
                moves += take * i;
                need -= take;
                balance[left] -= take;
            }
            if (need > 0 && balance[right] > 0 && left != right) {
                long long take = min(balance[right], need);
                moves += take * i;
                need -= take;
                balance[right] -= take;
            }
        }
        if(need==0) return moves;
        return -1;
    }
};