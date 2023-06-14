class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // using map because it is more reliant against discrepancies
        map<vector<int>,int> ourMap;
        int n = grid.size();
        for(int i = 0; i < n; i++) {
            vector<int> temp;
            for(int j = 0; j < n; j++) {
                temp.push_back(grid[i][j]);
            }

            if(ourMap.find(temp) != ourMap.end()) {
                ourMap[temp]++;
            } else {
                ourMap[temp] = 1;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<int> temp;
            for(int j = 0; j < n; j++) {
                temp.push_back(grid[j][i]);
            }

            if(ourMap.find(temp) != ourMap.end()) ans += ourMap[temp];
        }
        return ans;
    }
};