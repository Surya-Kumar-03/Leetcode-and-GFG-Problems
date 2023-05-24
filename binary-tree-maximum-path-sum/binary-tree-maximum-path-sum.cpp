/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int maxSum = INT_MIN;
    int ourMaxPath(TreeNode *root)
    {
        if (root == NULL) return 0;
        int left = ourMaxPath(root->left); //-2
        int right = ourMaxPath(root->right);  //3
        int passer = left + root->val;  //-1
        cout << "left: " << left << " right: " << right << " passer: " << passer;
        if((left + right + root->val) > passer) {
            passer = left + right + root->val; //2
            cout << " passer1: " << passer << " ";
        } 
        if (right + root -> val > passer) {
            passer = right + root -> val; //4
            cout << " passer2: " << passer << " ";
        }
        if(root->val > passer) {
            passer = root->val;
        }
        maxSum = max(maxSum, passer);
        cout << " I am on " << root->val << " : " << passer << " Max Sum: " << maxSum << endl; 
        return max(left + root->val, max(right + root -> val, root->val));
    }

    int maxPathSum(TreeNode *root)
    {
        ourMaxPath(root);
        return maxSum;
    }
};