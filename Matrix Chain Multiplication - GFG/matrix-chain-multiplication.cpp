//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int ourMatrix(int arr[],int i, int j, vector<vector<int>>& memo) {
    //     if(i == j) {
    //         return 0; // No Operations needed
    //     }   
        
    //     if(memo[i][j] != -1) {
    //         return memo[i][j];
    //     }
        
    //     int minSteps = INT_MAX;
    //     for(int k = i; k < j; k++) {
    //         int curPartition = ourMatrix(arr, i, k, memo) + 
    //                 ourMatrix(arr, k + 1, j, memo) +
    //                 (arr[i - 1] * arr[k] * arr[j]);
    //         minSteps = min(minSteps, curPartition);
    //     }
    //     return memo[i][j] = minSteps;
    // }
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        // vector<vector<int>> memo(N, vector<int>(N, -1));
        // return ourMatrix(arr, 1, N - 1, memo);
        
        vector<vector<int>> dp(N, vector<int>(N, 0));
    
        for (int len = 2; len < N; len++) {
            for (int i = 1; i < N - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                for (int k = i; k < j; k++) {
                    int curPartition = dp[i][k] + dp[k + 1][j] + 
                                (arr[i - 1] * arr[k] * arr[j]);
                    dp[i][j] = min(dp[i][j], curPartition);
                }
            }
        }
        
        return dp[1][N - 1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends