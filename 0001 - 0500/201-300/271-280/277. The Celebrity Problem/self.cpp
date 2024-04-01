class Solution {
    public:

    // to check if a knows b
    bool knows(int a, int b, vector<vector<int>>& M){
        return M[a][b];
    }

    // to check if if s.top is celebrity
    bool check(int a, vector<vector<int>>& M){
        for(int i=0; i<M.size(); i++){
            if(i!=a && M[i][a]==0) return false;
            if(M[a][i]==1) return false;
        }
        return true;
    }
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;
        n--;
        while(n>=0) s.push(n--);
        while(s.size() > 1){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(knows(a, b, M)) {
                if(knows(b, a, M));
                else s.push(b);
            }
            else if(knows(b, a, M)) s.push(a);
        }
        if(s.size()==0) return -1;
        if(check(s.top(), M)) return s.top();
        return -1;
    }
};