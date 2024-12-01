#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution{
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root , TreeNode* p , TreeNode* q){
            if(root == NULL){
                return NULL;
            } 
            if(root == p || root ==q){
                return root;
            }
            TreeNode* res1 = lowestCommonAncestor(root->left, p, q);
            TreeNode* res2 = lowestCommonAncestor(root->right, p, q);
            if(res1 != NULL && res2 != NULL){
                std::cout << root ->val << std::endl;
                return root;
            }
            return root;    
        }
};

int main(){
    Solution solu;
}
