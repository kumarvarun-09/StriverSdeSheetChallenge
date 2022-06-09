#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(!first && !second)
        return first;
    if(!first)
        return second;
    if(!second)
        return first;
    
    Node<int> * ans = NULL, *temp = NULL;
    if(first->data <= second-> data)
    {
        ans = temp  = first;
        first = first -> next;
    }
    else
    {
        ans = temp = second;
        second = second -> next;
    }
    while(first && second)
    {
        if(first->data <= second-> data)
        {
            temp -> next = first;
            temp = temp -> next;
            first = first -> next;
        }
        else
        {
            temp -> next = second;
            temp = temp -> next;
            second = second -> next;
        }
    }
    while(first)
    {
         temp -> next = first;
         temp = temp -> next;
         first = first -> next;
    }
    while(second)
    {
          temp -> next = second;
          temp = temp -> next;
          second = second -> next;   
    }
    temp -> next = NULL;
    return ans;
}
