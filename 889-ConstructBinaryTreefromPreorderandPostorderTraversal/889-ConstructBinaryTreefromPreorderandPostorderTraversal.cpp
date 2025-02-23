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
    TreeNode* constructTree(int preStart, int preEnd, int postStart, int postEnd, 
        vector<int>& preorder, unordered_map<int, int>& postMap) {
        if (preStart > preEnd || postStart > postEnd) {
            return nullptr;
        }        

        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart < preEnd) {
            int leftNode = preorder[preStart + 1];
            int indexInPostOrder = postMap[leftNode];
            int nodesInLeftSubTree = indexInPostOrder - postStart + 1;

            root->left = constructTree(preStart + 1, preStart + nodesInLeftSubTree, 
                postStart, indexInPostOrder, preorder, postMap);

            root->right = constructTree(preStart + nodesInLeftSubTree + 1, preEnd, 
                indexInPostOrder + 1, postEnd - 1, preorder, postMap);
        } 

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        // Preorder = Root, Left, Right
        // Postorder = Left, Right, Root
        // See Neetcode -> https://www.youtube.com/watch?v=H1nBu3L-2gQ

        int nodes = preorder.size();
        unordered_map<int, int> idxMap;

        for(int itr = 0; itr < nodes; itr++) {
            idxMap[postorder[itr]] = itr;
        }

        return constructTree(0, nodes - 1, 0, nodes - 1, preorder, idxMap);
    }
};