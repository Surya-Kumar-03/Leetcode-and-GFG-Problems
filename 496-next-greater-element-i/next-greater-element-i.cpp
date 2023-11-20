class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> ng;
        unordered_map<int,int> ngMap;
        for(auto num : nums2) {
            while(!ng.empty() && num > ng.top()) {
                ngMap[ng.top()] = num;
                ng.pop();
            }
            ng.push(num);
        }

        vector<int> ans;
        for(int num : nums1) {
            if(ngMap.find(num) != ngMap.end()) ans.push_back(ngMap[num]);
            else ans.push_back(-1);
        }
        return ans;
    }
};