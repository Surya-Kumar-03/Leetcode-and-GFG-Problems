class Solution {
public:
    int findNumOnes(vector<int> input, int n) {
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(input[mid] == 1) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++) {
            int count = findNumOnes(mat[i], n);
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