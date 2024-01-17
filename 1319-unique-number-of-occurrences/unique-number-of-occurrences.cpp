class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        unordered_set<int> uniq;
        for(auto ele : arr) {
            freq[ele]++;
        }

        for(auto ele : freq) {
            if(uniq.find(ele.second) != uniq.end()) {
                return false;
            } 
            uniq.insert(ele.second);
        }
        return true;
    }
};