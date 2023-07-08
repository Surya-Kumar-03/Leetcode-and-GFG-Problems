//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(arr[0] == 0) return -1;
        int curJump = arr[0];
        int maxJump = arr[0];
        int jumps = 1;
        for(int i = 1; i < n - 1; i++) {
            maxJump = max(maxJump, arr[i] + i);
            if(curJump == i) {
                if(maxJump == i) return -1;
                else {
                    curJump = maxJump;
                    jumps++;
                } 
            } 
        }
        return jumps;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends