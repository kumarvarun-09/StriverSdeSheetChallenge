/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void traverse(TreeNode* root, vector<int> &ans)
    {
        if(!root)
            return;
        
        traverse(root -> left, ans);
        traverse(root -> right, ans);
        ans.push_back(root -> data);
    }
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    traverse(root, ans);
    return ans;
}
