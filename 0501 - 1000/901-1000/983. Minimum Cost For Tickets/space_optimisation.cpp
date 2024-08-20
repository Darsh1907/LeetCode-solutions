// https://www.youtube.com/watch?v=U5f__4we_Jc&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=123

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = 0;
        queue<pair<int, int>> month;
        queue<pair<int, int>> week;
        for(int day: days) {
            // step1: remove expired days
            while(!month.empty() && month.front().first+30 <= day) month.pop();
            while(!week.empty() && week.front().first+7 <= day) week.pop();
            // step2: add cost for current day
            week.push({day, ans+costs[1]});
            month.push({day, ans+costs[2]});
            // ans update
            ans = min(ans+costs[0], min(week.front().second, month.front().second));
        }
        return ans;
    }
};