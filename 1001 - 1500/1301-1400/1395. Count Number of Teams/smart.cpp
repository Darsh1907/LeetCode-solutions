// Consider the middle element in a 3-element valid team. Just count how many bigger, smaller elements on his left & right sides.
// An O(n^2) is provided which is easy to implement.

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0;
        for(int i=1; i<rating.size()-1; i++) {
            int leftsmall=0, rightsmall=0, leftlarge=0, rightlarge=0;
            // elements left of rating[i]
            for(int j=0; j<i; j++) {
                if(rating[j] < rating[i]) leftsmall++;
                else if(rating[j] > rating[i]) leftlarge++;
            }
            // elements right of rating[i]
            for(int j=i+1; j<rating.size(); j++) {
                if(rating[j] < rating[i]) rightsmall++;
                else if(rating[j] > rating[i]) rightlarge++;
            }
            ans += ((leftsmall * rightlarge) + (leftlarge * rightsmall));
        }
        return ans;
    }
};