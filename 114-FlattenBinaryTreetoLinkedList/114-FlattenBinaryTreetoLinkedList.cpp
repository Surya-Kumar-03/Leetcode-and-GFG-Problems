// Last updated: 1/25/2026, 2:11:32 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    /*
15        Flattens a binary tree into a right-child skewed tree via preorder traversal
16        Returns: the last node that was traversal
17    */
18    TreeNode* flattenBinaryTree(TreeNode* root) {
19        if (root == nullptr) {
20            return nullptr;
21        }
22
23        if (root->left == nullptr && root->right == nullptr) {
24            return root;
25        }
26
27        TreeNode* leftChildBottomMostNode = flattenBinaryTree(root->left);
28        TreeNode* rightChildBottomMostNode = flattenBinaryTree(root->right);
29
30        if (leftChildBottomMostNode != nullptr) {
31            leftChildBottomMostNode->right = root->right;
32            root->right = root->left;
33            root->left = nullptr;
34        }
35
36        if (rightChildBottomMostNode != nullptr) {
37            return rightChildBottomMostNode;
38        }
39
40        return leftChildBottomMostNode;
41    }
42
43    void flatten(TreeNode* root) {
44        flattenBinaryTree(root);
45    }
46};