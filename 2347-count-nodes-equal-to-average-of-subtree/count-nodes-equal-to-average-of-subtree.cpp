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
    int ans = 0;
    pair<int,int> postOrder(TreeNode* root, int sum, int n) {
        if(root == NULL) return {0, 0};

        auto left = postOrder(root->left, sum, n);
        auto right = postOrder(root->right, sum, n);
        
        int curSum = root->val + left.first + right.first;
        int curN = 1 + left.second + right.second;

        if((curSum / curN) == root->val) ans++;
        return {curSum, curN};
    }

    int averageOfSubtree(TreeNode* root) {
        if(root == NULL) return 0;
        postOrder(root, 0, 0);
        return ans;
    }
};