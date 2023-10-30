class Solution {
public:
    static bool comp(int& a, int& b) {
        int setA = __builtin_popcount(a);
        int setB = __builtin_popcount(b);
        if(setA == setB) {
            return a < b;
        } else return setA < setB;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};