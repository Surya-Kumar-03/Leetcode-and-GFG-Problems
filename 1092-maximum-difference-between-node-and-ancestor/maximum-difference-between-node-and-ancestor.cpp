/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // int maxDiff(TreeNode* root, vector<int> ancestors) {
    //     if(root == NULL) {
    //         return 0;
    //     }

    //     int ans = INT_MIN;
    //     int n = ancestors.size(), bVal = root -> val;
    //     for(auto aVal : ancestors) {
    //         int cur = abs(aVal - bVal);
    //         ans = max(ans, cur);
    //     }

    //     ancestors.push_back(root->val);
    //     if(root->left) {
    //         int left = maxDiff(root->left, ancestors);
    //         ans = max(ans, left);
    //     }

    //     if(root->right) {
    //         int right = maxDiff(root->right, ancestors);
    //         ans = max(ans, right);
    //     }

    //     return ans;
    // }

    int maxDiff(TreeNode* root, int maxVal, int minVal) {
        if(root == NULL) {
            return 0;
        }
        maxVal = max(root->val, maxVal);
        minVal = min(root->val, minVal);

        int l = maxDiff(root->left, maxVal, minVal);
        int r = maxDiff(root->right, maxVal, minVal);
        return max(maxVal - minVal, max(l, r));
    }

    int maxAncestorDiff(TreeNode* root) {
        return maxDiff(root, root->val, root->val);
    }
};