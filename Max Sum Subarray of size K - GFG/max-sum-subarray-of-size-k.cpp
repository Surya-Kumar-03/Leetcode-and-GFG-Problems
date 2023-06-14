//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i = 0, j = K;
        long maxSum, curSum = 0; 
        
        for(int k = 0; k < K; k++) {
            curSum += Arr[k];
        }
        maxSum = curSum;
        
        while(j < N) {
            curSum -= Arr[i];
            curSum += Arr[j];
            maxSum = max(maxSum, curSum);
            j++, i++;
        }
        return maxSum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends