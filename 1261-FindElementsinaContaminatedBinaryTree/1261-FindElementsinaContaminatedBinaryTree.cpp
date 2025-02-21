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
class FindElements {
    unordered_set<int> cache;
public:
    FindElements(TreeNode* root) {
        cacheTree(root, 0);
    }

    void cacheTree(TreeNode* cur, int myNum) {
        if (cur == nullptr) {
            return;
        }

        cache.insert(myNum);
        cacheTree(cur->left, (myNum * 2) + 1);
        cacheTree(cur->right, (myNum * 2) + 2);
    } 
    
    bool find(int target) {
        return cache.find(target) != cache.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */