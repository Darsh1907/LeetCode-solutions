#include<queue>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char,int> umap;
        for(int i=0; i<n; i++) umap[s[i]]++;
        priority_queue<pair<int, char>> maxHeap;
        for(auto i=umap.begin(); i!=umap.end(); i++) maxHeap.push(make_pair(i->second,i->first));
        string ans;
        while (!maxHeap.empty()) {
            auto x = maxHeap.top();
            maxHeap.pop();
            if(ans.empty() || x.second!=ans.back()){
                ans += x.second;
                if(--x.first > 0) maxHeap.push(x);
            }
            else {
                if(maxHeap.empty()) return "";
                auto y = maxHeap.top();
                maxHeap.pop();
                ans += y.second;
                if(--y.first > 0) maxHeap.push(y);
                maxHeap.push(x);
            }
        }
        return ans;
    }
};