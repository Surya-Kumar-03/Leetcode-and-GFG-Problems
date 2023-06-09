//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isPrime(int num) {
        if(num <= 1) return false;
        if(num == 2 ||  num == 3) return true;
        if(num % 2 == 0 || num % 3 == 0) return false;
        for(int i = 5; i <=  sqrt(num); i += 6) {
            if((num % i == 0) || (num % (i + 2) == 0)) {
                return false;
            }
        }
        return true;
    }
  
    vector<int> primeRange(int M, int N) {
        // code here
        vector<int> ans;
        for(int i = M; i <= N; i++) {
            if(isPrime(i)) {
                ans.push_back(i);
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
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends