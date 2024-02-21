class Solution {
public:
    int countPrimes(int n) {
        vector<int> check;
        check.push_back(0);
        for(int i=1; i<n; i++){
            check.push_back(i);
        }
        int count = 0;
        for(int i=2; i<n; i++){
            if(check[i]>0){
                count++;
                int j = i+i;
                while(j<n){
                    if(check[j]>0) check[j] = (-1)*check[j];
                    j = j+i;
                }
            }
        }
        return count;
    }
};