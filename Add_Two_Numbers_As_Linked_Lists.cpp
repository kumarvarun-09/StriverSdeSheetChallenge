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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    // Write your code here.
    int sum = head1 -> data + head2 -> data;
    head1 = head1 -> next;
    head2 = head2 -> next;
    Node * ans = new Node(sum % 10), *temp(ans);
    ans -> next = NULL;
    sum /= 10;
    while(head1 && head2)
    {
        sum = sum + head1 -> data + head2 -> data;
        temp -> next = new Node(sum % 10);
        sum /= 10;
        temp = temp -> next;
        temp -> next = NULL;
        head1 = head1 -> next;
        head2 = head2 -> next;
    }
    while(head1)
    {
        sum += head1 -> data;
        temp -> next = new Node(sum % 10);
        sum /= 10;
        temp = temp -> next;
        temp -> next = NULL;
        head1 = head1 -> next;
    }
    while(head2)
    {
        sum += head2 -> data;
        temp -> next = new Node(sum % 10);
        sum /= 10;
        temp = temp -> next;
        temp -> next = NULL;
        head2 = head2 -> next;
    }
    while(sum)
    {
        temp -> next = new Node(sum % 10);
        sum /= 10;
        temp = temp -> next;
        temp -> next = NULL; 
    }
    return ans;
}
