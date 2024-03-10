class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        map<string, int> mp1;
        map<string, int> mp2;
        for(int i=0; i<words1.size(); i++) mp1[words1[i]]++;
        for(int i=0; i<words2.size(); i++) mp2[words2[i]]++;
        auto p = mp1.begin();
        auto q = mp2.begin();
        int result = 0;
        while(p!=mp1.end() && q!=mp2.end()){
            if(p->first == q->first){
                if(p->second==1 && q->second==1) result++;
                p++;
                q++;
            }
            else if(p->first < q->first) p++;
            else q++;
        }
        return result;
    }
};