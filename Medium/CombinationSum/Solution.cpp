#include <iostream>
#include <vector>

class Solution{
<<<<<<< HEAD
    public:
        std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target){
            std::vector<std::vector<int>> combinations;
            std::vector<int> path;
            backTrack(combinations,candidates,path,target,0);
            for(std::vector<int> path : combinations){
                for(int i : path){
                    std::cout << i << " " ;
                }
                std::cout << "\n" ;
            }
            return combinations;
        }
    private:
        void backTrack(std::vector<std::vector<int>>& combinations,std::vector<int>& candidates,std::vector<int>& path, int target,int indx){
            if(target == 0){
                combinations.push_back(path);
                return;
            }
            if(target < 0){
                return;
            }
            for(int i = indx ; i < candidates.size() ; i ++){
                path.push_back(candidates[i]); 
                backTrack(combinations,candidates,path,target-candidates[i],i);
                path.pop_back();
            }
            return;
        }
};

int main(){
    std::vector<int> nums = {2,3,6,7};
    Solution solu;
    solu.combinationSum(nums,7);
=======
    std::vector<std::vector<int>> ans; 
    public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target){
        for(int i = 0 ; i < candidates.size(); i++){
            std::vector<int> paths;
            treeState(candidates,i,0,target,paths);
        }  
        return ans;
    }
    private:
    void treeState(std::vector<int>& candidates, int startInd , int sum , int remainingSum,std::vector<int>& paths){
        if(startInd == candidates.size()){
            if(remainingSum == 0){
                ans.push_back(paths);     
            }
            return;
        }
        if(candidates[startInd] <= remainingSum){
            paths.push_back(candidates[startInd]);
            treeState(candidates,startInd,sum,remainingSum - candidates[startInd],paths);
            std::cout << remainingSum  << std::endl;
            paths.pop_back();
        }  
        treeState(candidates,startInd+1,sum,remainingSum,paths);
    }
};
    
int main(){
    Solution solu;
    std::vector<int> canididates = {2,3,6,7};
    std::vector<std::vector<int>> allPaths = solu.combinationSum(canididates,7); 
    for(std::vector<int> vectors: allPaths){
        for(int i : vectors){
            std::cout << i << " ";
        }
        std::cout <<" "<<std::endl;;
    } 
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
}
