/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int maxDepth(TreeNode *root)
        {
            if (root == NULL) return 0;
            queue<TreeNode*> pending;
            pending.push(root);
            int level = 0;
            while (!pending.empty())
            {
                int size = pending.size();
                for (int i = 0; i < size; i++)
                {
                    TreeNode *node = pending.front();
                    pending.pop();
                    if (node->left) pending.push(node->left);
                    if (node->right) pending.push(node->right);
                }
                level++;
            }
            return level;
        }

   	// int maxDepth(TreeNode* root) {
   	//    	// recursive
   	//     if(root == NULL) return 0;
   	//     int lh = maxDepth(root->left);
   	//     int rh = maxDepth(root->right);
   	//     return 1 + max(lh, rh);
   	// }
};