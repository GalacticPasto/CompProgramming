#include <iostream>
#include <vector>
#include <queue>

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
        std::vector<std::vector<int>> levelOrder(TreeNode* root){
            std::vector<std::vector<int>> ans;
            std::queue<TreeNode*> q; 
            q.push(root); 
                
            while(!q.empty()){
                int i = q.size();
                std::vector<int> level;
                while(i--){
                    if(q.front() == nullptr){
                        q.pop();
                        continue;
                    }
                    level.push_back((q.front())->val);
                    TreeNode* node = q.front();
                    q.push(node->left);
                    q.push(node->right);
                    q.pop();
                }
                if(level.size()==0)continue;
                ans.push_back(level);
            }
            return ans;
        }
};
