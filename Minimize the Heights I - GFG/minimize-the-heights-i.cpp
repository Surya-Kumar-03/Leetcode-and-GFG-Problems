//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int A[], int N, int K) {
        // code here
        sort(A, A + N);
        int res = A[N - 1] - A[0];
        int left = A[0] + K, right = A[N - 1] - K;
        for (int i = 0; i < N - 1; i++) {
            int maxi = max(A[i] + K, right), mini = min(left, A[i + 1] - K);
            res = min(res, maxi - mini);
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