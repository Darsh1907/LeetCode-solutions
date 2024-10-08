class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int ,vector<int>,greater<int>> pq;
        vector<int>a;
        for(auto it:hand)
        pq.push(it);
        int temp=1;
        int i=0;
        while(i<hand.size()) {
            int prev=pq.top();
            pq.pop();
            while(temp<groupSize && !pq.empty()){
                if(pq.top()-1==prev){
                prev= pq.top();
                pq.pop();
                temp++;
                }
                else if(pq.top()==prev){
                    a.push_back(pq.top());
                    pq.pop();
                }
                else{
                    return false;
                }
            }
            if(temp!=groupSize) return false;
            for(int i=0;i<a.size();i++) pq.push(a[i]);
            a.resize(0);
            i=i+temp;
            temp=1; 
        }
        return true;
    }
};