class Solution {
public:
    string largestWordCount(const vector<string> &messages, const vector<string> &senders) {
        unordered_map<string, int> chat;
        int n = senders.size();
        for(int i = 0; i < n; i++) {
            int words = 1;
            for(char c : messages[i]) {
                if(c == ' ') words++;
            }
            chat[senders[i]] += words;
        }
        string name = "";
        int words = 0;
        for(auto x : chat) {
            if(x.second > words) {
                words = x.second;
                name = x.first;
            }
            else if(x.second == words){
                if(x.first > name) name = x.first;
            }
        }

        return name;
    }
};