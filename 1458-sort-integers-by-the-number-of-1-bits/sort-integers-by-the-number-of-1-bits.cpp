class Solution {
public:
    static int getSetBits(int num) {
        int setBits = 0;
        for(int i = 0; i <= 31; i++) {
            if((num >> i) & 1) setBits++;
        }
        return setBits;
    }

    static bool comp(int& a, int& b) {
        // int setA = __builtin_popcount(a);
        // int setB = __builtin_popcount(b);

        int setA = getSetBits(a);
        int setB = getSetBits(b);
        if(setA == setB) {
            return a < b;
        } else return setA < setB;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};