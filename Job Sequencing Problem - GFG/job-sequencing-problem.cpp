//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job j1, Job j2) {
        return j1.profit > j2.profit;    
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // sort with highest profit to achieve max profit
        sort(arr, arr+n, comp);
        vector<bool> profits(n, false); // false indicates the position isn't filled
        int profit = 0, jobCount = 0;
        for(int i = 0; i < n; i++) {
            int j = arr[i].dead - 1;
            while(j >= 0) {
                if(profits[j] == false) {
                    profit += arr[i].profit;
                    jobCount++;
                    profits[j] = true; //indicates this deadline is filled
                    break;
                }
                j--;
            }
        }
        return {jobCount, profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends