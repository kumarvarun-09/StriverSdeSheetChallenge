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

Node *findMiddle(Node *head) {
    // Write your code here
    Node * temp(head);
    int count = 0;
    while(temp)
    {
        temp = temp -> next;
        count++;
    }
    temp = head;
    count /= 2;
    while(count--)
    {
        temp = temp -> next;
    }
    return temp;
}
