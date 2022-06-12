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

Node *firstNode(Node *head)
{
	//    Write your code here.
    if(!head)
        return NULL;
    Node * slow = head, * fast = head;
    while(fast -> next && fast -> next -> next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
        {
            Node * start = head;
            while(start != slow)
            {
                start = start -> next;
                slow = slow -> next;
            }
            return start;
        }
    }
    return NULL;
    }
