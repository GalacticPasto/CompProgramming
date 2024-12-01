#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
    
class Solution{
    int count = 0;
    public:
        int pathSum(TreeNode* root, int targetSum){
            if(root){
                dfs(root,targetSum);
                pathSum(root->left,targetSum);
                pathSum(root->right,targetSum);
            }
            return count;
        }
    private:
        void dfs(TreeNode* root, int targetSum){
            if(!root)return;
            if(root->val == targetSum)count++; 
            dfs(root->left, targetSum - root->val);
            dfs(root->right, targetSum - root->val);
        }
};

int main(){
    TreeNode *node = new TreeNode(10);
    TreeNode *left= new TreeNode(5);
    TreeNode *leftLeft= new TreeNode(3);
    TreeNode *leftLeftLeft= new TreeNode(3);
    TreeNode *leftLeftRight= new TreeNode(-2);
    TreeNode *leftRight= new TreeNode(2);
    TreeNode *leftRightRight= new TreeNode(1);
    node->left = left;
    left->left = leftLeft;
    leftLeft->left = leftLeftLeft;
    leftLeft->right = leftLeftRight;
    left->right = leftRight;
    leftRight->right = leftRightRight;
    TreeNode *right = new TreeNode(-3);
    TreeNode *rightRight= new TreeNode(11);
    node->right = right; 
    right->right = rightRight;
    

    Solution solu;
    int count = solu.pathSum(node,8);
    std::cout << count << "\n";
}

