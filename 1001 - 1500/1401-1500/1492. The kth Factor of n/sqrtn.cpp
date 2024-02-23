class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> s;
        for(int i=1; i<=sqrt(n); i++){
            if(n%i == 0){
                s.insert(i);
                s.insert(n/i);
            }
        }
        if(k>s.size()) return -1;
        return *next(s.begin(), k-1);
    }
};