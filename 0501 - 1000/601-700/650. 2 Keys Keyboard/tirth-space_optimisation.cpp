class Solution {
public:
    int minSteps(int n) {
        vector<int> res(1005);
        res[0]=0;
        res[1]=0;
        res[2]=2;
        res[3]=3;
        for(int i=4;i<=n;i++){
            res[i]=i;
            for(int j=2;j<i;j++){
                if(i%j==0) res[i]=min(res[i],res[i/j]+j);
            }
        }
        return res[n];
    }
};