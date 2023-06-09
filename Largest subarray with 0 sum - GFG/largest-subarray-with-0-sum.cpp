//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
        public:
        int maxLen(vector<int>&A, int n)
    {
       // Your code here
        unordered_map<int, int> ourMap; //stores sumtill that element and start index
        ourMap[0] = -1; // to handle the case where the whole array becomes zero
        // indicates sum was zero for the subarray in the start
        // testcase -> -1 1 -1 1
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            sum += A[i];
            if(ourMap.find(sum) != ourMap.end()){
                ans = max(ans, i - ourMap[sum]);
            }
            else ourMap[sum] = i;
        }
        return ans;
    }
    
    

    // int maxLen(vector<int>&A, int n)
    // {   
    //     unordered_map<int, int> ourMap;
    //     int prefixSum = 0, maxDis = 0;
    //     ourMap[0] = -1;
    //     for(int i = 0; i < n; i++) {
    //         prefixSum += A[i];
    //         if(ourMap.find(prefixSum) != ourMap.end()) {
    //             int dis = (i - ourMap[prefixSum]);
    //             maxDis = max(maxDis, dis);
    //         } else ourMap[prefixSum] = i;
    //     }
    //     return maxDis;
    // }    
        
     
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends