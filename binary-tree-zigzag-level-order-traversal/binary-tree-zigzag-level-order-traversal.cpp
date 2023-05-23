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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        bool leftToRight = true;
        queue<TreeNode*> pending;
        pending.push(root);
        while(!pending.empty()) {
            int size = pending.size();
            vector<int> temp(size);
            for(int i = 0; i < size; i++) {
                int j = i;
                if(!leftToRight) j = size - i - 1;
                TreeNode* node = pending.front();
                pending.pop();
                temp[j] = node->val;
                if(node->left) pending.push(node->left);
                if(node->right) pending.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(temp);
        }
        return ans;
    }
};