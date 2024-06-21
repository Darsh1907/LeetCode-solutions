class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;
        if(s == "") return s;
        int cnt = 0;
        int n = s.size();
        for(int i=0; i<n; i++) {
            if(s[i]=='(') {
                st.push('(');
                cnt++;
            }
            else {
                if(cnt==1){
                    string t = "";
                    while(st.size()>1) {
                        t = st.top()+t;
                        st.pop();
                    }            
                    ans += t;
                    if(!st.empty()) st.pop(); 
                    cnt = 0; 
                }
                else {
                    st.push(')');
                    cnt--;
                }
            }
        }
        return ans;
    }
};