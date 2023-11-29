class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> b(n);
        string bits = b.to_string();
        int ans = 0;
        for(char bit : bits) {
            if(bit == '1') ans += 1;
        }
        return ans;
    }
};