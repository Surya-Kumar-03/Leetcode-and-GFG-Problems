//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool findithBit(int i, long long X) {
        if (((1LL << (i - 1)) & X) != 0) return true;
        else return false;
    }

    
    long long reversedBits(long long X) {
        long long ans = 0;
        for (int i = 1; i <= 32; i++) {
            if (findithBit(i, X)) {
                ans = (1LL << (32 - i)) | ans;
            }
        }
        return ans;
    }

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends