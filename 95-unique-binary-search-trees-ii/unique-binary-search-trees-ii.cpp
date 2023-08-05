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
    vector<TreeNode*> generateSubtrees(int s, int e) {
        vector<TreeNode*> res;
        if (s > e) {
            res.push_back(nullptr); // empty tree
            return res;
        }

        for (int i = s; i <= e; ++i) {
            vector<TreeNode*> leftSubtrees = generateSubtrees(s, i - 1);
            vector<TreeNode*> rightSubtrees = generateSubtrees(i + 1, e);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateSubtrees(1, n);
        
    }
};