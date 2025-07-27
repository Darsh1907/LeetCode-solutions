class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> newArr = getCleanArr(nums);
        int newSize = newArr.size();
        if (newSize < 3) {
            return 0;
        }
        int res = 0;
        for(int i=1; i<newSize-1; i++) {
            if(newArr[i-1] < newArr[i] && newArr[i] > newArr[i+1]) res++;
            else if (newArr[i-1] > newArr[i] && newArr[i] < newArr[i+1]) res++;
        }
        return res;
    }
    vector<int> getCleanArr(vector<int>& old) {
        int size = old.size();
        vector<int> newArr;
        newArr.push_back(old[0]);
        for(int i=1; i<size; i++) {
            if(old[i] != newArr.back()) newArr.push_back(old[i]);
        }
        return newArr;
    }
};