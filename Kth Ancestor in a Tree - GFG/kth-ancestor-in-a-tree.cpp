//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
// 1107/1120 test cases passed
// int kthNode(Node* cur, unordered_map<Node*, Node*> parentMap, int k) {
//     if(k == 0) return cur->data;
//     if(parentMap[cur] == NULL) return -1;
//     return kthNode(parentMap[cur], parentMap, k-1);
// }

// int finder(Node* root, int k, int node, unordered_map<Node*, Node*>& parentMap) {
//     if(root == NULL) return -1;
//     if(root->data == node) {
//         return kthNode(root, parentMap, k);
//     }
//     int left = -1, right = -1;
//     if(root->left) {
//         parentMap[root->left] = root;
//         left = finder(root->left, k, node, parentMap);
//     }
//     if(root->right) {
//         parentMap[root->right] = root;
//         right = finder(root->right, k, node, parentMap);
//     }
//     return max(left, right);
// }

bool finder(Node* root, int k, int node, vector<int>& ancestors) {
    if(root == NULL) return false;
    if(root->data == node) {
        return true;
    }
    
    int left = false, right = false;
    if(root->left) {
        left = finder(root->left, k, node, ancestors);
    }
    if(root->right) {
        right = finder(root->right, k, node, ancestors);
    }
    
    if(left || right && ancestors.size() <= k) {
        ancestors.push_back(root->data);
        return true;
    }
    return false;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    // unordered_map<Node*, Node*> parentMap;
    // parentMap[root] = NULL;
    // return finder(root, k, node, parentMap);
    
    vector<int> ancestors;
    finder(root, k, node, ancestors);
    if(ancestors.size() < k) return -1;
    else return ancestors[k - 1];
}
