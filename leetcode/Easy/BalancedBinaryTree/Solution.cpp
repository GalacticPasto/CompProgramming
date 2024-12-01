struct TreeNode {
    int val;
    struct TreeNode left;
    struct TreeNode right;
};

bool isBalanced(struct TreeNode* root) {
    int left = depth(root->left);
    int right = depth(root->right);
    if((left + 1 > right) | (right +1 > left))return false;
    return true;
}
int depth(struct TreeNode* root){
    if(root == NULL)
    {
        return 0;
    }
    int left = depth(root->left);
    int right = depth(root->right);
    return ((left >= right ? left : right)+1);
}
