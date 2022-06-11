#include <bits/stdc++.h> 
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node * d1 = firstHead, * d2 = secondHead;
    while(d1 && d2)
    {
        if(d1 == d2)
        {
            if(!d1)
                break;
            return d1 -> data;
        }
        
        d1 = d1 -> next;
        d2 = d2 -> next;
        if(!d1 && d2)
        {
            d1 = secondHead;
        }
        if(d1 && !d2)
        {
            d2 = firstHead;
        }
    }
    return -1;
}
