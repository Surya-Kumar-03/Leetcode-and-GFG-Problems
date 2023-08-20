//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

Node* mergeTwoLists(Node* one, Node* two) {
    if(!one) return two;
    if(!two) return one;
    
    Node* dummy = new Node(0);
    Node* res = dummy;
    while(one != NULL && two != NULL) {
        if(one->data < two->data) {
            dummy->bottom = one;
            one = one->bottom;
        } else {
            dummy->bottom = two;
            two = two->bottom;
        }
        dummy = dummy->bottom;
    }
    
    if(one != NULL) {
        dummy->bottom = one;
    } else {
        dummy->bottom = two;
    }
    
    return res->bottom;
}    
    
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL || root->next == NULL) {
       return root;
   }
   
   root->next = flatten(root->next); // do the magic of recursing and getting me the merge till that point
   
   root = mergeTwoLists(root, root->next); //now come you get merged
   
   return root; //for the next guy take the merged
}

