#include <iostream>
#include <queue>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode* root)
{
    std::queue<TreeNode*> queue;
    int max = 0;
    queue.push(root); 
    int i = 1;
    while(!queue.empty())
    {
        std::vector<int> data;
        int n = queue.size();
        int ans = 0 << i;
        
        while(n--)
        {
            TreeNode* node = queue.front();
            queue.pop();
            if(node->left != nullptr)
            {
                data.push_back(1);
                queue.push(node->left);
            } 
            else
            {
                data.push_back(0);
            }
            if(node->right != nullptr)
            {
                data.push_back(1);
                queue.push(node->right);
            } 
            else
            {
                data.push_back(0);
            }
        }
        int lmin = 0;
        int lmax = 0;
        for(int j = 0 ; j < data.size() ; j++)
        {
            if(data[j] == 1)
            {
                lmin = std::min(j,min);
                lmax = std::max(j,max);
            }
        }
        max = ans - lmin - lmax;
    }
    return max;
}
