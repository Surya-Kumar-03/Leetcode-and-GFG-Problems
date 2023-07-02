//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int cost(vector<int>& height, int n, int k, int i, vector<int>& memo) {
        if(i == n - 1) return 0;
        if(memo[i] != -1) return memo[i];
        int minCost = INT_MAX;
        for(int j = 0; j < k; j++) {
            if(j + i + 1 >= n) break;
            int curContender = cost(height, n, k, i + j + 1, memo) + 
                abs(height[j + i + 1] - height[i]);
            minCost = min(minCost, curContender);
        }
        return memo[i] = minCost;
    }
    
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int> memo(n + 1, -1);
        return cost(height, n, k, 0, memo);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends