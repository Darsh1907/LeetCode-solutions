// Refer: https://www.youtube.com/watch?v=V-gYS2b8Ux0

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for(int i=0; i<profit.size(); i++) jobs.push_back({difficulty[i], profit[i]});

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0, best = 0, i = 0;
        for (int ability : worker) {
            while (i<jobs.size() && ability>=jobs[i].first) {
                best = max(best, jobs[i].second);
                i++;
            }
            maxProfit += best;
        }
        return maxProfit;
    }
};