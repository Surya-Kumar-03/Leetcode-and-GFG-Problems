class Solution {
public:
        int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
        return dp[m][n];
    }
};

// class Solution {
// public:
//     int ourMax(vector<int> nums1,unordered_map<int, vector<int>> ourMap, int cur, int range, vector<vector<int>>& memo)  {
//         if(cur == nums1.size() || range == nums1.size()) return 0;
//         if(range != -1 && memo[cur][range] != -1) return memo[cur][range];
//         if(ourMap.find(nums1[cur]) != ourMap.end()) {
//             auto temp =  ourMap[nums1[cur]];
//             int maxUncrossed = 0;
//             for(int i = 0; i < temp.size(); i++) {
//                 // Check for all possibilities
//                 if(temp[i] > range) {
//                     int currentTry = 1 + ourMax(nums1, ourMap, cur + 1, temp[i], memo);
//                     maxUncrossed = max(maxUncrossed, currentTry);
//                 }
//             }
//             // with and without cross
//             memo[cur][range] = max(maxUncrossed, ourMax(nums1, ourMap, cur + 1, range, memo));
//             return memo[cur][range];
//         } 
//         memo[cur][range] = ourMax(nums1, ourMap, cur + 1, range, memo);
//         return memo[cur][range];
//     }

//     int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, vector<int>> ourMap;
//         int n = nums1.size();
//         vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
//         for(int i = 0; i < nums2.size(); i++) {
//             ourMap[nums2[i]].push_back(i);
//         }
//         return ourMax(nums1, ourMap, 0, -1, memo);
//     }
// };