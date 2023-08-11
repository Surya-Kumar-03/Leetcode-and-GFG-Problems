class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> ourMap;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (ourMap.find(val) != ourMap.end()) return false;
        nums.push_back(val); //put the new value in the last
        ourMap[val] = nums.size() - 1; //say that it is in the last index to Map
        return true;
    }
    
    bool remove(int removingGuy) {
        if (ourMap.find(removingGuy) == ourMap.end()) return false;
        int lastValue = nums.back(); //get lastElement
        ourMap[lastValue] = ourMap[removingGuy]; //change it to the element being removed
        nums[ourMap[removingGuy]] = lastValue; 
        nums.pop_back();
        ourMap.erase(removingGuy);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */