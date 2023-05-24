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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val);
        TreeNode* node = root;
        bool valueInserted = false;
        while(!valueInserted)
        {
            if(val > node->val)
            {
                if(node->right == NULL)
                {
                    node->right = new TreeNode(val);
                    valueInserted = true;
                }
                else node = node->right;
            }
            if(val < node->val) //go left
            {
                if(node->left == NULL)
                {
                    node->left = new TreeNode(val);
                    valueInserted = true;
                }
                else node = node->left;
            }
        }
        return root;
    }
};