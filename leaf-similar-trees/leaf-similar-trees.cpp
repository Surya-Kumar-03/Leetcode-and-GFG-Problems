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
    void getLeafs(TreeNode* root,vector<int>& leafs) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            leafs.push_back(root->val);
            return;
        }
        if(root->left) getLeafs(root->left, leafs);
        if(root->right) getLeafs(root->right, leafs);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafs1;
        vector<int> leafs2;
        getLeafs(root1, leafs1);
        getLeafs(root2, leafs2);
        return leafs1 == leafs2;
    }
};