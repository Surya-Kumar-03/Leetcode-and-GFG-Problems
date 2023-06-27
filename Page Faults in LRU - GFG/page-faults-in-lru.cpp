//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        // code here
        map<int, int> pageMap;
        int pageFaultCount = 0;
    
        for (int i = 0; i < n; i++) {
            if (pageMap.find(pages[i]) == pageMap.end()) {
                pageMap[pages[i]] = i;
                pageFaultCount++;
            } else {
                pageMap[pages[i]] = i;
            }
    
            int minIndex = INT_MAX;
            if (pageMap.size() > c) {
                for (auto it : pageMap) {
                    minIndex = min(it.second, minIndex);
                }
                pageMap.erase(pages[minIndex]);
            }
        }
    
        return pageFaultCount;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends