//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        queue<int> police;
        queue<int> theives;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] == 'P') {
                police.push(i);
            } else theives.push(i);
        }
    
    
        int ans = 0;
        while(police.size() && theives.size()) {
            if(abs(((int)police.front() - (int)theives.front())) <= k) {
                ans++;
                police.pop();
                theives.pop();
            } 
            else if (police.front() < theives.front()) {
                police.pop();
            } 
            else {
                theives.pop();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends