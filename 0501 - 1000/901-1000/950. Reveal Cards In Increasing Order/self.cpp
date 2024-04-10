#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if(deck.size()==1) return deck;
        sort(deck.begin(), deck.end());
        deque<int> dq;
        dq.push_back(deck.back());
        for(int i=deck.size()-2; i>=0; i--) {
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(deck[i]);
        }
        vector<int> result;
        for(auto i=dq.begin(); i!=dq.end(); i++) result.push_back(*i);
        return result;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;
    // Create a vector to store the deck of cards
    vector<int> deck = {17,13,11,2,3,5,7};
    // Call the deckRevealedIncreasing function and store the result
    vector<int> result = solution.deckRevealedIncreasing(deck);
    // Print the result
    for (int i : result) cout << i << " ";
    cout << endl;
    return 0;
}