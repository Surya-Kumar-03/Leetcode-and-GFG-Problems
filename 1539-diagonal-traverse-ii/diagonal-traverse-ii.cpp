class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // Brute force is to group them with row + col and store them in a vector
        int rows = nums.size();
        queue<pair<int,int>> pending;
        vector<int> ans;
        pending.push({0, 0});

        while(!pending.empty()) {
            int groupSize = pending.size();
            for(int i = 0; i < groupSize; i++) {
                auto topEle = pending.front();
                int row = topEle.first;
                int col = topEle.second;
                ans.push_back(nums[row][col]);

                if(row + 1 < rows && col == 0) {
                    pending.push({row + 1, col});
                }

                if(col + 1 < nums[row].size()) {
                    pending.push({row, col + 1});
                }
                pending.pop();
            }
        }

        return ans;
    }
};