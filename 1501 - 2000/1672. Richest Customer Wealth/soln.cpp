class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int temp;
        int max = 0;
        for(int i=0; i<accounts.size(); i++){
            temp = 0;
            for(int j=0; j<accounts[i].size(); j++){
                temp = temp + accounts[i][j];
            }
            if(temp>max) max=temp;
        }
        return max;
    }
};