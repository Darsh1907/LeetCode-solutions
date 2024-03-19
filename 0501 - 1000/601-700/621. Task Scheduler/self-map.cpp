class Solution {
private:
    int max(int a, int b){
        if(a>=b) return a;
        return b;
    }
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        unordered_map<char, int> umap;
        int max_freq = 0;
        int num_of_max = 0;
        for(int i=0; i<tasks.size(); i++){
            umap[tasks[i]]++;
            if(umap[tasks[i]] > max_freq){
                max_freq = umap[tasks[i]];
                num_of_max = 1;
            }
            else if(umap[tasks[i]]==max_freq) num_of_max++;
        }
        return max((max_freq-1)*(n+1)+num_of_max, tasks.size());
    }
};