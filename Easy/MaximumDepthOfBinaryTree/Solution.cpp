#inlcude <iostream>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

int maxDepth(TreeNode* root) {
    int left = maxDepth(root->left); 
    int right = maxDepth(root->right); 
    int ans = std::max(left,right);
    return ans + 1;
}


