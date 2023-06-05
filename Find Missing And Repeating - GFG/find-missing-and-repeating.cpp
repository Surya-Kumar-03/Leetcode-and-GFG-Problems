//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, long long n) {
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    
        // Calculate S and S2:
        for (long long i = 0; i < n; i++) {
            SN -= arr[i];
            S2N -= (long long)arr[i] * (long long)arr[i];
        }
    
        //Find X+Y = (X^2-Y^2)/(X-Y):
        S2N = S2N / SN;
    
        //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
        // Here, X-Y = SN and X+Y = S2N:
        long long x = (SN + S2N) / 2;
        long long y = x - SN;
    
        return {(int)y, (int)x};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends