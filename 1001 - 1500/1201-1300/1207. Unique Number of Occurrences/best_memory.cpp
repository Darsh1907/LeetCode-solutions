class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr){
        int i = 0;
        sort(arr.begin(),arr.end());
        vector<int> an;
        while (i < arr.size()){
            int count = 1;
            for (int j = i+1;j<arr.size();j++){
                if (arr[i] == arr[j]) count++;
            }
            an.push_back(count);
            i = i + count;
        }
        sort(an.begin(),an.end());
        for (int i = 0; i < an.size() - 1; i++){
            if (an[i] == an [i+1]) return false;
        }
        return true;
    } 
};