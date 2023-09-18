class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) break;
                count++;
            }
            pq.push({count, i});
        }

        vector<int> ans;
        while(k-- > 0) {
            auto rowI = pq.top().second;
            pq.pop();
            ans.push_back(rowI);
        }
        return ans;
    }
};