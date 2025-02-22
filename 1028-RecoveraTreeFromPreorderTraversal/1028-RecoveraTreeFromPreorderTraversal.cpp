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
    int getUnderscoreCountTillNextNum(string& traversalStr, int& curIndex) {
        int size = traversalStr.size();
        int underScoreCount = 0;

        for (int itr = curIndex; itr < size; itr++) {
            if (traversalStr[itr] == '-') {
                underScoreCount++;
            } else {
                break;
            }
        }

        return underScoreCount;
    }

    string getFirstNum(string& traversalStr, int& curIndex) {
        int size = traversalStr.size();
        string curNum = "";

        for (int itr = curIndex; itr < size; itr++) {
            if (isdigit(traversalStr[itr]) == false) {
                break;
            }

            curNum += traversalStr[itr];
        }

        return curNum;
    }

    TreeNode* constructTree(string& traversal, int depthExpected,
                            int& curIndex) {
        if (curIndex == traversal.size()) {
            return nullptr;
        }

        int depthInTraversal =
            getUnderscoreCountTillNextNum(traversal, curIndex);
        if (depthInTraversal != depthExpected) {
            return nullptr;
        }

        curIndex += depthInTraversal;

        TreeNode* subTreeNode = new TreeNode();
        string curVal = getFirstNum(traversal, curIndex);
        subTreeNode->val = stoi(curVal);
        curIndex += curVal.size();

        subTreeNode->left = constructTree(traversal, depthExpected + 1, curIndex);
        subTreeNode->right = constructTree(traversal, depthExpected + 1, curIndex);

        return subTreeNode;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        if (traversal.empty()) {
            return nullptr;
        }

        int curIndex = 0;
        return constructTree(traversal, 0, curIndex);
    }
};