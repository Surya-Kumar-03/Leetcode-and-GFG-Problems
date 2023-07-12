/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> getParents(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        //do bfs
        queue<TreeNode*> pending;
        pending.push(root);
        parentMap[root] = NULL; //No Parent
        while(!pending.empty()) {
            auto parent = pending.front();
            if(parent->left) {
                parentMap[parent->left] = parent;
                pending.push(parent->left);
            }
            if(parent->right) {
                parentMap[parent->right] = parent;
                pending.push(parent->right);
            }
            pending.pop();
        }
        return parentMap;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentMap = getParents(root);
        
        //do bfs again to find the nodes
        unordered_set<int> visited;
        queue<TreeNode*> pending;
        pending.push(target);
        visited.insert(target->val);
        int curDistance = 0;
        while(!pending.empty()) {
            if(curDistance == k) break;
            curDistance++;
            int size = pending.size();
            for(int i = 0; i < size; i++) {
                auto topEle = pending.front();
                pending.pop();
                if(parentMap[topEle] && (visited.find(parentMap[topEle]->val) == visited.end())) {
                    visited.insert(parentMap[topEle]->val);
                    pending.push(parentMap[topEle]);
                }
                if(topEle->left && (visited.find(topEle->left->val) == visited.end())) {
                    visited.insert(topEle->left->val);
                    pending.push(topEle->left);
                }
                if(topEle->right && (visited.find(topEle->right->val) == visited.end())) {
                    visited.insert(topEle->right->val);
                    pending.push(topEle->right);
                }
            }
        }
        vector<int> ans;
        while(!pending.empty()) {
            auto topEle = pending.front();
            ans.push_back(topEle->val);
            pending.pop();
        }
        return ans;
    }
};