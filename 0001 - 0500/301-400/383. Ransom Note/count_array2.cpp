class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[256] = {0};
        for(const auto &m : magazine) ++count[m];
        for(const auto &r : ransomNote) if(--count[r] < 0) return false;
        return true;
    }
};