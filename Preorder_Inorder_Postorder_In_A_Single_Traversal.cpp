/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

void inOrder(BinaryTreeNode<int> *root, vector<int> &v)
{
    if(!root)
        return;
    inOrder(root -> left, v);
    v.push_back(root -> data);
    inOrder(root -> right, v);
}
void preOrder(BinaryTreeNode<int> *root, vector<int> &v)
{
    if(!root)
        return;
    v.push_back(root -> data);
    preOrder(root -> left, v);
    preOrder(root -> right, v);
}
void postOrder(BinaryTreeNode<int> *root, vector<int> &v)
{
    if(!root)
        return;
    postOrder(root -> left, v);
    postOrder(root -> right, v);
    v.push_back(root -> data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> in, pre, post;
    inOrder(root, in);
    preOrder(root, pre);
    postOrder(root, post);
    return {in, pre, post};
}
