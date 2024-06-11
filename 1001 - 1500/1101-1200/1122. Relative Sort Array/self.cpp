#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    std::vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        map<int, int> arr1map;
        for(int i=0; i<arr1.size(); i++) arr1map[arr1[i]]++;

        for(int i=0; i<arr2.size(); i++) {
            auto ptr = arr1map.find(arr2[i]);
            int count = ptr->second;
            while(count--) res.push_back(arr2[i]);
            ptr->second = 0;
            arr1map.erase(ptr);  // You may or may not keep this line
        }

        for(auto i=arr1map.begin(); i!=arr1map.end(); i++) {
            int count = i->second;
            while(count--) res.push_back(i->first);
        }

        return res;
    }
};