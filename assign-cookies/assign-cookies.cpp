class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end()); //sorting helps us get the minimum size cookie
        sort(s.begin(), s.end());  //             for a guy
        int i = 0; // iterating in people array
        // j iterates through cookies array
        // run loop till there are cookies and people left
        for(int j = 0; i < g.size() && j < s.size(); j++) {
            if(g[i] <= s[j]) i++; // this guy is satisfied
        }
        return i; //it holds the satisfied guys
    }

    // My Brute force
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     int contentCount = 0, j = 0;
    //     sort(g.begin(), g.end());
    //     sort(s.begin(), s.end());
    //     for(int i = 0; i < g.size(); i++) {
    //         while(j < s.size() && g[i] > s[j]) {
    //             j++;
    //         } 
    //         if(j >= s.size()) break;
    //         else {
    //             if(g[i] <= s[j]) {
    //                 contentCount++;
    //                 j++;
    //             } else break;
    //         }
    //     }
    //     return contentCount;
    // }
};