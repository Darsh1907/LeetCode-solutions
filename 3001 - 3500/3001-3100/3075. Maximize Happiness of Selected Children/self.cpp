class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int decr = 0;
        long long result = 0;
        for(int i=happiness.size()-1; i>=0 && k>0; i--){
            if(decr<=happiness[i]) result += happiness[i] - decr;
            decr++;
            k--;
        }
        return result;
    }
};