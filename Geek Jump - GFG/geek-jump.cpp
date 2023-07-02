//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int ourReach(vector<int>& height, int n, int i, vector<int>& memo) {
    //     if(i == n - 1) return 0;
    //     if(memo[i] != -1) return memo[i];
    //     int left = INT_MAX, right = INT_MAX;
    //     if(i + 1 < n)
    //         left = ourReach(height, n, i + 1, memo) + abs(height[i + 1] - height[i]);
    //     if(i + 2 < n)
    //         right = ourReach(height, n, i + 2, memo) + abs(height[i + 2] - height[i]);
    //     return memo[i] = min(left, right);
    // }
    
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        // vector<int> memo(n, -1);
        // return ourReach(height, n, 0, memo);
        
        // vector<int> dp(n);
        // dp[n - 1] = 0; //base case
        // for(int j = n - 2; j >= 0; j--) {
        //     int oneJump = INT_MAX;
        //     int twoJump = INT_MAX;
        //     if(j + 1 < n) oneJump = dp[j + 1] + abs(height[j + 1] - height[j]);
        //     if(j + 2 < n) twoJump = dp[j + 2] + abs(height[j + 2] - height[j]);
        //     dp[j] = min(oneJump, twoJump);
        // }
        // return dp[0];
        
        int prev = 0;
        int prevLast = 0;
        int cur;
        for(int j = n - 2; j >= 0; j--) {
            int oneJump = INT_MAX;
            int twoJump = INT_MAX;
            if(j + 1 < n) oneJump = prev + abs(height[j + 1] - height[j]);
            if(j + 2 < n) twoJump = prevLast + abs(height[j + 2] - height[j]);
            cur = min(oneJump, twoJump);
            prevLast = prev;
            prev = cur;
        }
        return cur;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends