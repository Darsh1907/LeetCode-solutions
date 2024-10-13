// Using Maps and Arrays
// https://www.youtube.com/watch?v=WtkwD7ikxfg

class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int, int> mp; // actual value -> index
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()) {
            arr.push_back(val);
            mp[val] = arr.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        auto ptr = mp.find(val);
        int ind = ptr->second;
        arr[ind] = arr.back();
        mp[arr.back()] = ind;
        arr.pop_back();
        mp.erase(ptr);
        return true;
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */