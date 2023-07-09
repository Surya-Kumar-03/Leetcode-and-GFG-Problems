//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        
        //maximum possible difference
        int res = arr[n - 1] - arr[0];
        
        int left = arr[0] + k, right = arr[n - 1] - k;
        for(int i = 0; i < n - 1; i++) {
            if(arr[i + 1] - k < 0) continue; //ignore neg
            int maxGuy = max(right, arr[i] + k);
            int minGuy = min(left, arr[i + 1] - k);
            res = min(res, maxGuy - minGuy);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends