#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
     // Write your code here.
    if(!head || !head -> next || !k)
        return head;
    Node * temp = head;
    int len = 0;
    while(temp)
    {
        len++;
        temp = temp -> next;
    }
    k %= len;
    if(!k)//special case when after reversing also list will become same as current
        return head;
    
    temp = head;
    for(int i = 1; i < len - k; i++)
    {
        temp = temp -> next;
    }
    Node * newHead = temp -> next; //newhead
    temp -> next = NULL; //new end of linked list
    
    temp = newHead;
    while(temp -> next)
    {
        temp = temp -> next;
    }
    temp -> next = head;
    return newHead;
}
