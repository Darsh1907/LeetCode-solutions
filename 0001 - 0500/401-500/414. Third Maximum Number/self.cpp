class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> temp;
        for(int i=0; i<nums.size(); i++){
            temp.insert(nums[i]);
        }
        //Given that If the third maximum does not exist, return the maximum number.
        if(temp.size()==1 || temp.size()==2){
            auto it = temp.end(); // temp.end() has the next empty position of the set
            // The last element (max element) resides in (temp.end()-1)th position
            it--;
            return *it;
        }
        // If third max element exists.
        auto it = temp.end(); // it = last empty position
        it--; // *it = Max element
        it--; // *it = Second max element
        it--; // *it = Third max element
        return *it;
    }
};