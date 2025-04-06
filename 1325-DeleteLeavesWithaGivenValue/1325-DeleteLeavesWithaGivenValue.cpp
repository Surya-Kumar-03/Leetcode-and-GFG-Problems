// Last updated: 4/6/2025, 6:43:16 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool removeLeaves(TreeNode* node, int& target) {
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val == target) {
                return true;
            } else {
                return false;
            }
        }

        bool isLeafByLeft = false, isLeafByRight = false;

        if (node->left) {
            if (removeLeaves(node->left, target)) {
                delete node->left;
                node->left = nullptr;
                isLeafByLeft = true;
            } 
        } else {
            isLeafByLeft = true;
        }

        if (node->right) {
            if (removeLeaves(node->right, target)) {
                delete node->right;
                node->right = nullptr;
                isLeafByRight = true;
            }
        } else {
            isLeafByRight = true;
        }

        if (isLeafByLeft && isLeafByRight && target == node->val) {
            return true;
        }

        return false;
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (removeLeaves(root, target)) {
            return nullptr;
        }

        return root;
    }
};