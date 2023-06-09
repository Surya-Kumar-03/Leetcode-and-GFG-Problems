//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        string num = to_string(n);
        int size = num.size();
        int sum = 0;
        while(n > 0) {
            int lastDig = n % 10;
            n /= 10;
            sum += pow(lastDig, size);
        }
        if(sum == stoi(num)) return "Yes";
        else return "No";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends