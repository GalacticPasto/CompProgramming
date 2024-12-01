struct TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode left, TreeNode right) : val(x), left(left), right(right) {}
};
void helper(TreeNode* root, std::vector<std::vector<int>>& result, bool order)
{
    if(root == nullptr)
    {
        return;
    }
    std::queue<int> queue; 

    if(root->left != nullptr)
    {
        queue.push(root->left->val);
        helper(root->left,result,!order);
    }
    if(root->right != nullptr)
    {
        queue.push(root->right->val);
        helper(root->left,result,!order);
    }
    std::vector<int> vector;
    while(!queue.empty())
    {
        vector.push_back(queue.front());
        queue.pop();
    }
    if(!order)
    {
        std::reverse(vector.begin(),vector.end());
        result.push_back(vector);
    }
    else
    {
        result.push_back(vector);
    }
    return;
}
std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    std::vector<std::vector<int>> result;
    helper(root,result,true);
    return result;
}

