#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/

Node *flattenLinkedList(Node *root)
{
   // Your code here
   if(!root)
   return root;
   vector<int> ans;
   Node * temp = root;
   while(temp)
   {
       ans.push_back(temp->data);
       Node * t2 = temp -> child;
       while(t2)
       {
           ans.push_back(t2->data);
           t2 = t2 -> child;
       }
       temp = temp -> next;
   }
   sort(ans.begin(), ans.end());
   temp = new Node(ans.front());
   Node * newRoot = temp;
   for(int i = 1; i < ans.size(); i++)
   {
       temp -> child = new Node(ans[i]);
       temp = temp -> child;
   }
   return newRoot;
}
