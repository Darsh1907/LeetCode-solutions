class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case
        if(s.size()==1) return s;
        if(numRows == 1) return s;
        // Take string to store answer
        string ans = "";
        // We are going to traverse each row
        for(int row=0; row<numRows ; row++){
            // for each row the next chracter is at index 2*(n -1) 
            int increment = 2*(numRows -1);
            // For first and last rows 
            for(int i = row; i < s.length(); i+= increment){
                ans += s[i];
                // For middle rows there will be extra characters
                if(row > 0 && row < numRows-1 && i+increment - 2 * row < s.length()){
                    ans += s[i+increment - 2 * row];
                }
            }
        }
        return ans;
    }
};