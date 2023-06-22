//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>> ratios(n);
        for(int i = 0; i < n; i++) {
            double ratio = (double)arr[i].value / arr[i].weight;
            ratios[i] = {ratio, i};
        }
        sort(ratios.rbegin(), ratios.rend());
        int curWeight = 0;
        double curVal = 0.0; 
        int i = 0;
        while(i < n && curWeight < W) {
            auto cur = ratios[i];
            if(curWeight + arr[cur.second].weight > W) {
                curVal += ((W - curWeight) * cur.first);
                curWeight = W; //knapsack is full
            } else {
                curWeight += arr[cur.second].weight;
                curVal += arr[cur.second].value;
            }
            i++;
        }
        return curVal;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends