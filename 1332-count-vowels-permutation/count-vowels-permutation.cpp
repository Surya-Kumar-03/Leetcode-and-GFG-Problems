class Solution {
public:
    int MOD = 1e9 + 7;
    vector<char> options(char c) {
        switch(c) {
            case 'a': 
                return {'e'};
            case 'e': 
                return {'a', 'i'};
            case 'i': 
                return {'a', 'e', 'o', 'u'};
            case 'o':
                return {'i', 'u'};
            case 'u': 
                return {'a'};
            case ' ':
                return {'a', 'e', 'i', 'o', 'u'};
        }
        return {};
    }

    int permute(int n, char last, int size, unordered_map<string, int>& memo) {
        if(size == n) {
            return 1;
        }

        string key = to_string(last) + '_' + to_string(size);
        if(memo.find(key) != memo.end()) {
            return memo[key];
        }

        vector<char> opt = options(last);
        int ans = 0;
        for(auto ch : opt) {
            ans = (ans + (long long)permute(n, ch, size + 1, memo)) % MOD;
        }
        return memo[key] = ans;
    }

    int countVowelPermutation(int n) {
        unordered_map<string, int> memo;
        return permute(n, ' ', 0, memo);
    }
};