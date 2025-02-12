class Solution {
public:
    int sumOfDigits(int x) {
        int sum = 0;
        while(x > 0) {
            sum = sum + (x % 10);
            x = x / 10;
        }
        return sum;
    } 

    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, pair<int,int>> mp;
        for(auto &num : nums) {
            int cur = sumOfDigits(num);
            if(mp.find(cur) == mp.end()) {
                mp[cur].first = num;
                mp[cur].second = -1;
            }
            else {
                int firstMax = mp[cur].first, secondMax = mp[cur].second;
                if(num >= firstMax) {
                    secondMax = firstMax;
                    firstMax = num;
                }
                else if(num < firstMax && num >= secondMax) {
                    secondMax = num;
                }
                ans = max(ans, firstMax + secondMax);
                mp[cur].first = firstMax;
                mp[cur].second = secondMax;
            }
        }
        return ans;
    }
};