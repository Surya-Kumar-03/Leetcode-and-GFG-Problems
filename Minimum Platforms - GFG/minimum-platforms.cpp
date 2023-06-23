//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int ar[], int dep[], int n)
    {
    	// Your code here
    	// greedy approach O(Nlogn) O(1)
    	sort(ar, ar+n);
    	sort(dep, dep+n);
    	int maxi = 0, cur = 0;
    	int j = 0;
    	for(int i = 0; i < n; i++) {
    	    while(dep[j] < ar[i]) {
    	        cur--;
    	        j++;
    	    }
    	    cur++;
    	    maxi = max(maxi, cur);
    	}
    	return maxi;
    	
    	// using pq O(nlogn) O(n)
    // 	vector<pair<int,int>> arr(n);
    // 	for(int i = 0; i < arr.size(); i++) {
    // 	   arr[i] = {ar[i], dep[i]};
    // 	}
    // 	sort(arr.begin(), arr.end());
    // 	priority_queue<int, vector<int>, greater<int>> pq;
    // 	int platforms = 0, cur = 0;
    // 	for(int i = 0; i < n; i++) {
    // 	    while(!pq.empty() && (pq.top() < arr[i].first)) {
    // 	        pq.pop();
    // 	        cur--;
    // 	    }
    // 	    pq.push(arr[i].second);
    // 	    cur++;
    // 	    platforms = max(platforms, cur);
    // 	}
    // 	return platforms;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends