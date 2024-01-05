#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int size = flowerbed.size();
        for (int i=0; i<size; i++) {
            if (flowerbed[i]==0 && (i==0 || flowerbed[i-1]==0) && (i==size-1 || flowerbed[i+1]==0)) {
                flowerbed[i] = 1;
                count++;
            }
        }
        return count >= n;
    }
};

int main() {
    // Example usage
    Solution solution;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;
    bool canPlace = solution.canPlaceFlowers(flowerbed, n);
    cout << "Can place flowers: " << (canPlace ? "Yes" : "No") << endl;
    return 0;
}