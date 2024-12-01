#include <iostream>
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int findBottomLeftValue(TreeNode* root) 
{
    int ans;
    std::queue<TreeNode*> queue;
    queue.push(root); 
    while(!queue.empty())
    {
        int n = queue.size();
        std::vector<int> data;
        while(n--)
        {
            TreeNode* node = queue.front(); 
            data.push_back(node);
            queue.pop();
            
            if(node->left != nullptr)
            {
                queue.push(node->left);
            }
            if(node->right != nullptr)
            {
                queue.push(node->right);
            }
        }
        ans = data[0];
    }
    return ans;
}
