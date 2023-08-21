//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printSquare(int n) {
        // code here
        // cout << n << endl;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << n - min(i,j) + 1 << " ";
                // cout << i << " " << j << "  ";
            }
            
            for(int j = n - 1; j > 0; j--) {
                cout << max(n - i, n - j) + 1 << " ";
                // cout << i << " " << j << "  ";
            }
            
            cout << endl;
        }
        
        for(int i = n - 1; i > 0; i--) {
            for(int j = 1; j <= n; j++) {
                cout << n - min(i,j) + 1 << " ";
                // cout << i << " " << j << "  ";
            }
            
            for(int j = n - 1; j > 0; j--) {
                cout << max(n - i, n - j) + 1 << " ";
                // cout << i << " " << j << "  ";
            }
            cout << endl;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends