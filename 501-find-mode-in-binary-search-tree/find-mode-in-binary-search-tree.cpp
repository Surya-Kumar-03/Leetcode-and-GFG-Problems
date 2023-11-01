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
    vector<int> ans;
    int curFreq = 0, maxFreq = 0, cur = 0;

    void inorder(TreeNode* root) {
        // cout << "i am at " << root->val << endl;
        // cout << curFreq << " " << maxFreq << " " << cur << endl;
        // for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        // cout << endl << endl;
        if(root->left) inorder(root->left);

        if(root->val == cur) 
            curFreq++;
        else curFreq = 1;

        if(curFreq > maxFreq) {
            ans = {root->val};
            maxFreq = curFreq;
        } else if(curFreq == maxFreq) {
            ans.push_back(root->val);
        }

        cur = root->val;
        
        if(root->right) inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        if(root == NULL) return {};
        inorder(root);
        return ans;
    }
};