// Last updated: 7/4/2025, 10:24:40 PM
class Solution {
public:
    char kthCharacter(long long k, vector<int>& arr) {
        int c = 0; 
        k--;
        for (int i = 0; k != 0; i++, k >>= 1) {
            c += ((k & 1) & arr[i]);
        }
        return (char)((c % 26) + 'a');
    }
};