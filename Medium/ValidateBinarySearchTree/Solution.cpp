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
    public: 
        bool isBST(TreeNode* root){
            return helper(root,-1000000000000,1000000000000);
        }   
        bool helper(TreeNode* root, long long min , long long max){
            if(root == NULL){
                return true;
            }
            if(min >= root-> val || root -> val >= max){
                return false;
            }
            bool left = helper(root->left,min,root-> val);
            if(left){
                bool right = helper(root->right,root->val , max);
                return right;
            }
            return false;
        }

};
int main(){
    TreeNode left(1);
    TreeNode right(3);
    TreeNode root(2,&left,&right);
    Solution solu;
    std::cout << solu.isBST(&root)<< std::endl;
    std::cout << true << std::endl;
    std::cout << false << std::endl;
}
