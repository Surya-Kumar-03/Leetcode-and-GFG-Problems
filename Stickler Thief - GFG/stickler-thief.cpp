//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int prev = 0, prevLast = 0, cur;
        for(int j = n - 1; j >= 0; j--) {
            int choose = arr[j], notChoose = INT_MIN;
            if(j + 2 < n) {
                choose += prevLast;
            }
            if(j + 1 < n) {
                notChoose = prev;
            }
            cur = max(choose, notChoose);
            prevLast = prev;
            prev = cur;
        }
        return cur;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends