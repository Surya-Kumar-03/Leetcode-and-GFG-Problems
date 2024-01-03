class Solution {
public:
    int getBits(string curRow) {
        int bits = 0;
        for(auto ch : curRow) {
            if(ch == '1') {
                bits++;
            }
        }
        return bits;
    }

    int numberOfBeams(vector<string>& bank) {
        int last = getBits(bank[0]);
        int n = bank.size();
        int ans = 0;

        for(int i = 1; i < n; i++) {
            int cur = getBits(bank[i]);
            if(cur > 0) {
                ans += (last * cur);
                last = cur;
            }
        }
        return ans;
    }
};