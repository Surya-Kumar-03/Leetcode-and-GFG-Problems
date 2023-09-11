class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        int n = groupSizes.size();

        for(int i = 0; i < n; i++) {
            int ele = groupSizes[i];
            if(mp.find(ele) != mp.end() && mp[ele].size() == ele) {
                ans.push_back(mp[ele]); 
                mp.erase(ele);
            }
            mp[ele].push_back(i);
        }

        for(auto keys : mp) {
            ans.push_back(keys.second);
        }

        return ans;
    }
};