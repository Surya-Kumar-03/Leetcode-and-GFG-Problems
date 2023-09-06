//{ Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public: 
    int countSmaller(vector<vector<int>>& matrix, int R, int C, int target) 
    {
        int ans = 0;
        for(int i = 0; i < R; i++) 
        {
            int low = 0;
            int high = C - 1;
            while(low <= high) {
                int mid = low + ((high - low) / 2);
                if(matrix[i][mid] <= target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } 
            ans += low;
        }
        return ans;
    }
    
    int median(vector<vector < int>> &matrix, int R, int C)
    {
       	// code here     
       	// brute force
       	// vector<int> array;
       	// for(int i = 0; i < R; i++) {
       	//     for(int j = 0; j<  C; j++) {
       	//         array.push_back(matrix[i][j]);
       	//     }
       	// }
        // sort(array.begin(), array.end());
        // return array[(R * C)/2];
        
        int low = 0;
        int high = INT_MAX;
        int correctPos = ((R * C) / 2);
        
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            int count = countSmaller(matrix, R, C, mid);
            if(count <= correctPos) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector < int>> matrix(r, vector<int> (c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix, r, c);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends