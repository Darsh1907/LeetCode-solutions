class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int coordi1_num = coordinate1.back() - '0';
        int coordi2_num = coordinate2.back() - '0';
        int coordi1_char = coordinate1[0] - 'a' + 1;
        int coordi2_char = coordinate2[0] - 'a' + 1;
        bool is_odd1 = ((coordi1_num%2) == (coordi1_char%2));
        bool is_odd2 = ((coordi2_num%2) == (coordi2_char%2));
        return (is_odd1 == is_odd2);
    }
};