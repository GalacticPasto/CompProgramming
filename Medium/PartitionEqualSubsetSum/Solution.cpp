#include <ctime>
#include <iostream>
#include <vector>
#include <unordered_set>
class Solution{
    public:
        bool canPartition(std::vector<int>& nums){

            std::vector<std::vector<int>> subsets;
            std::vector<int> subset;
            std::unordered_set<int> set;
            generateSubsets(nums,subsets,subset,0);
            bool canPartition = false;

            for(std::vector<int> sub : subsets){
                int add = 0;
                for(int i : sub){
                    add+= i;
                }
                canPartition = subsetsEqualsK(subsets,sub,add,nums.size());
                if(canPartition)break;
            }
            return canPartition;
        }
    private:
        bool subsetsEqualsK(std::vector<std::vector<int>>& subsets, std::vector<int>& subset,int k,int numsSize){
            int n = subset.size();
            for(std::vector<int> sub : subsets){
                if(sub.size() == numsSize-n){
                    int add = 0;
                    for(int i = 0 ; i < sub.size() ; i++){
                        if(sub[i] == subset[i])return false;
                        add+= sub[i];
                    }
                    if(add == k)return true;
                }
            }
            return false;
        } 
        void generateSubsets(std::vector<int>& nums,std::vector<std::vector<int>>& subsets,std::vector<int> subset,int indx){
            if(indx == nums.size()){
                subsets.push_back(subset);
                return;
            }
            subset.push_back(nums[indx]);
            generateSubsets(nums,subsets,subset,indx+1);
            subset.pop_back();
            generateSubsets(nums,subsets,subset,indx+1);
            return;
        }
};

int main(){
    std::vector<int> nums = {1,5,11,5};
    Solution solu;
    bool can = solu.canPartition(nums);
    std::cout << can << "\n";
}
