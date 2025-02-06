class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monotonicStack;
        unordered_map<int, int> nextGreaterStore;

        int n2 = nums2.size();

        for(int i = n2 - 1; i >= 0; i--) {
            while (!monotonicStack.empty() && nums2[i] > monotonicStack.top()) {
                monotonicStack.pop();
            }

            if (!monotonicStack.empty()) {
                nextGreaterStore[nums2[i]] = monotonicStack.top();
            } else {
                nextGreaterStore[nums2[i]] = -1;
            }

            monotonicStack.push(nums2[i]);
        }

        int n1 = nums1.size();
        vector<int> ans;
        for(int i = 0; i < n1; i++) {
            ans.push_back(nextGreaterStore[nums1[i]]);
        }

        return ans;
    }
};