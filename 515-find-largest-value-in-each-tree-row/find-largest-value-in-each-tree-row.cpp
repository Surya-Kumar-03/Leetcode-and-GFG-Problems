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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> pending;
        pending.push(root);
        
        vector<int> ans;
        while(!pending.empty()) {
            int levelSize = pending.size();
            int maxi = INT_MIN;

            for(int i = 0; i < levelSize; i++) {
                auto top = pending.front();
                pending.pop();

                maxi = max(maxi, top->val);
                if(top->left) {
                    pending.push(top->left);
                }
                if(top->right) {
                    pending.push(top->right);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};