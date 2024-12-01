#include <iostream>
#include <vector>
#include <unordered_map>

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
        TreeNode* buildTree(std::vector<int>& preOrder , std::vector<int>& inOrder){
            std::unordered_map<int, int> map;
            for(int i = 0 ; i < inOrder.size(); i++){
                map[inOrder[i]] = i;
            }
            TreeNode *root = helper(preOrder,inOrder,map,0,preOrder.size()-1,0,inOrder.size()-1);
            return root;
        }
    private:
        TreeNode* helper(std::vector<int>&preOrder, std::vector<int>& inorder, std::unordered_map<int,int>& map, int preStart,int preEnd, int inStart,int inEnd ){
            if(preStart > preEnd || inStart > inEnd){
                return NULL;
            } 
            TreeNode* root = new TreeNode(preOrder[preStart]);
            
            int inRoot = map[root->val];
            int numsLeft = inRoot - inStart; 
            
            root->left = helper(preOrder, inorder,map, preStart+1, preStart+numsLeft, inStart, inRoot-1);
            root->right= helper(preOrder, inorder,map, preStart+numsLeft+1, preEnd,inRoot+1,inEnd);

            return root;
        }
};
class Display{
    public:
        void preOrderTraversal(TreeNode* root){
            if(root == nullptr){
                return;
            }
            std::cout << root->val << "," ;
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
        void inOrderTraversal(TreeNode* root){
            if(root == nullptr){
                return;
            }
            inOrderTraversal(root->left);
            std::cout << root->val << "," ;
            inOrderTraversal(root->right);
        }
        void postOrderTraversal(TreeNode* root){
            if(root == nullptr){
                return;
            }
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            std::cout << root->val << "," ;
        }
};

int main(){

    std::vector<int> preOrder = {1,2, 4 ,6 ,7 ,5 ,8 ,9, 3, 10, 11, 12, 13};
    std::vector<int> inOrder = {6,4,7,2,8,5,9,1,10,3,12,11,13};
    Solution solu; 
    Display print; 
    TreeNode* node= solu.buildTree(preOrder,inOrder);

    print.preOrderTraversal(node);
    std::cout << "\n";
    print.inOrderTraversal(node);
    std::cout << "\n";
    print.postOrderTraversal(node);
    std::cout << "\n";

    TreeNode rightRightRight(13);
    TreeNode rightRightLeft (12);
    TreeNode rightRight (11);
    TreeNode rightLeft  (10);
    TreeNode right (3);
    TreeNode leftRightRight (9);
    TreeNode leftRightLeft (8);
    TreeNode leftRight  (5);
    TreeNode leftLeftRight (7);
    TreeNode leftLeftLeft (6);
    TreeNode leftLeft  (4);
    TreeNode left (2);
    TreeNode root  (1);
    
    root.left = &left;
    root.right= &right;
    left.left = &leftLeft;
    leftLeft.left = &leftLeftLeft;
    leftLeft.right= &leftLeftRight;
    left.right = &leftRight; 
    leftRight.left = &leftRightLeft;
    leftRight.right= &leftRightRight;
    right.left = &rightLeft;
    right.right = &rightRight;
    rightRight.left = &rightRightLeft;
    rightRight.right= &rightRightRight;
}
