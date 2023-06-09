//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
// 	int maxSum(int *arr, int n, int i, vector<int>& memo) {
// 	    if(i >= n) return 0;
// 	    if(memo[i] != -1) return memo[i];
// 	    int pick = arr[i] + maxSum(arr, n, i + 2, memo);
// 	    int notPick = maxSum(arr, n, i + 1, memo);
// 	    return memo[i] = max(pick, notPick);
// 	}
	
	int findMaxSum(int *arr, int n) {
	   // code here
	   // vector<int> memo(n, -1);
	   // return maxSum(arr, n, 0, memo);
	   
	   //vector<int> dp(n, 0);
	   //for(int j = n - 1; j >= 0; j--) {
	   //    int pick = arr[j], notPick = INT_MIN;
	   //    if(j + 2 < n) {
	   //        pick += dp[j + 2];
	   //    }
	   //    if(j + 1 < n) {
	   //        notPick = dp[j + 1];
	   //    }
	   //    dp[j] = max(pick, notPick);
	   //}
	   //return dp[0];
	   
	   int prev = 0, prevLast = 0, cur;
	   for(int j = n - 1; j >= 0; j--) {
	       int pick = arr[j], notPick = INT_MIN;
	       if(j + 2 < n) {
	           pick += prevLast;
	       }
	       if(j + 1 < n) {
	           notPick = prev;
	       }
	       cur = max(pick, notPick);
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
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends