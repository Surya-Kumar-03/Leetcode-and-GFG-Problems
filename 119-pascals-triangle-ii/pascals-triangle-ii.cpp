class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> a(r + 1);
        a[0] = 1;
        for(int i = 1; i < r + 1; i++) {
            for(int j = i; j >= 1; j--) {
                a[j] += a[j - 1];
            }
        }
        return a;
    }

    // vector<int> getRow(int r) {
    //     vector<vector<int>> ps;
    //     ps.push_back({1});
    //     for(int i = 1; i <= r; i++) {
    //         vector<int> tmp;
    //         tmp.push_back(1);
    //         for(int j = 0; j < i - 1; j++) {
    //             tmp.push_back(ps[i - 1][j] + ps[i - 1][j + 1]);
    //         }
    //         tmp.push_back(1);
    //         ps.push_back(tmp);
    //     }
    //     return ps[r];
    // }
};