class Solution {
public:
    bool isop(string a) {
        if(a=="+" || a=="*" || a=="-" || a=="/") return true;
        return false;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> mystack;
        for(int i=0; i<tokens.size(); i++){
            if(isop(tokens[i])){
                int x = mystack.top();
                mystack.pop();
                int y = mystack.top();
                mystack.pop();
                int result;
                if(tokens[i]=="+") result=x+y;
                if(tokens[i]=="*") result=x*y;
                if(tokens[i]=="-") result=y-x;
                if(tokens[i]=="/") result=y/x;
                mystack.push(result);
            }
            else mystack.push(stoi(tokens[i]));
        }
        return mystack.top();
    }
};