//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n = bt.size();
        if(n == 0) return 0;
        vector<int> wt(n);
        int curWt = 0;
        int cumWt = 0;
        sort(bt.begin(), bt.end());
        for(int i = 0; i < n - 1; i++) {
            curWt += bt[i];
            cumWt += curWt;
        }
        int ans = cumWt / n;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        int ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends