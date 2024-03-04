class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int left = 0;
        int right = tokens.size()-1;
        while(left<=right) {
            if(tokens[left]<=power){
                power = power - tokens[left];
                score++;
                left++;
            }
            else {
                if(left==right) return score;
                if(score==0) return 0;
                score--;
                power = power+tokens[right];
                right--;
            }
        }
        return score;
    }
};