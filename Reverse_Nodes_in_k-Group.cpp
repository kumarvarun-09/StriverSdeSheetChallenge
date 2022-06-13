#include<vector>
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
Node *reverse(Node* head, int i, int n, vector<int> b, int len)
{
    if(i == n || !head || !head -> next)
        return head;
    int k = b[i];
    Node *p1 = head, *p2 = head -> next, *p3 = head -> next -> next;
    while(--k && p2)
    {
        p2 -> next = p1;
        p1 = p2;
        p2 = p3;
        if(p3)
            p3 = p3 -> next;
    }
    if(i < n - 1)
    head -> next = reverse(p2, i + 1, n, b, len - b[i + 1]);
    else head -> next = p2;
    return p1;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    Node * temp = head;
    int len = 0;
    while(temp)
    {
        len++;
        temp = temp -> next;
    }
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        if(b[i] > 0)
            v.push_back(b[i]);
    }
    return reverse(head, 0, v.size(), v, len - b[0]);
}
