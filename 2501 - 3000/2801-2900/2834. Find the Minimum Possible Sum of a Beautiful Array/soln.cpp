class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        set<int> s;
        int size = 0;
        int num = 1;
        
        long long result = 0;
        
        while(size<n) {
            if(s.find(target-num) == s.end()){
                s.insert(num);
                result = result+num;
                num++;
                size++; 
            }
            else num++;
        }
        return result;
    }
};