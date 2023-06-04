//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
         vector<int> res(2);
        long totalN = (long) n*(n+1)/2;
        long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        
        for (int i = 0; i < n; i++) {

            int remain = n - abs(arr[i]);

            if (arr[remain] > 0){
                arr[remain] *= -1;
            }else{
                res[0] = abs(arr[i]);
            }
        }        sum = sum - res[0];
        res[1] = (int) (totalN - sum);

        return res;
        
// long long SN = (n * (n + 1)) / 2;
//     long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

//     // Calculate S and S2:
//     long long S = 0, S2 = 0;
//     for (int i = 0; i < n; i++) {
//         S += arr[i];
//         S2 += (long long)arr[i] * (long long)arr[i];
//     }

//     //S-Sn = X-Y:
//     long long val1 = S - SN;

//     // S2-S2n = X^2-Y^2:
//     long long val2 = S2 - S2N;

//     //Find X+Y = (X^2-Y^2)/(X-Y):
//     val2 = val2 / val1;

//     //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
//     // Here, X-Y = val1 and X+Y = val2:
//     long long x = (val1 + val2) / 2;
//     long long y = x - val1;

//     return {(int)x, (int)y};
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