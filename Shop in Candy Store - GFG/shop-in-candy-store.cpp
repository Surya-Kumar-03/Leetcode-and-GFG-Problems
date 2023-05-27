//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int> ans;
        sort(candies, candies+N); // {1 2 3 4}
        int i = 0, j = N - 1;
        int minMoney = 0;
        while(i <= j) {
            minMoney += candies[i];
            j -= K;
            i++;
        }
        ans.push_back(minMoney);
        int maxMoney = 0;
        i = N - 1, j = 0;
        while(i >= j) {
            maxMoney += candies[i];
            j += K;
            i--;
        }
        ans.push_back(maxMoney);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends