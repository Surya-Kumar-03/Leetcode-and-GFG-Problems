//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long a = A, b = B;
        long long gcd = 1;
        while(a > 0 && b > 0) {
            if(a > b) a = a % b;
            else b = b % a;
        }
        if(a == 0) gcd = b;
        else gcd = a;
        long long lcm = (A * B)/gcd;
        return {lcm, gcd};
    }
    
    // vector<long long> lcmAndGcd(long long A , long long B) {
    //     // code here
    //     vector<long long> ans;
    //     ans.push_back((A*B)/__gcd(A,B));
    //     ans.push_back(__gcd(A, B));
    //     return ans;
    // }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends