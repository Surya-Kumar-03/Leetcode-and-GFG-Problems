class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> options;
        int nminusOneFact = 1;
        for(int i = 1; i < n; i++) { //take nminusOneFact 
            nminusOneFact *= i;
            options.push_back(i);
        }
        options.push_back(n); //last number add to options
        k -= 1; //to match our vector indexing

        string ans = "";
        while(true) {
            ans += to_string(options[(k / nminusOneFact)]);
            options.erase(options.begin() + (k / nminusOneFact));
            if(options.size() == 0) {
                break;
            }
            
            k %= nminusOneFact;
            nminusOneFact = nminusOneFact / (options.size());
        }
        return ans;

        // using stl
        // vector<int> num;
        // for(int i = 1; i <= n; i++) {
        //     num.push_back(i);
        // }

        // for(int i = 0; i < k - 1; i++) {
        //     next_permutation(num.begin(), num.end());
        // }

        // string ans = "";
        // for(auto ele : num) {
        //     ans += to_string(ele);
        // }
        // return ans;
    }
};