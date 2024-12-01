#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
    public:
        std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target){
            std::vector<std::vector<int>> combinations;
            std::vector<int> path;
            sort(candidates.begin(), candidates.end());
            backTrack(combinations,candidates,path,target,0);
            for(std::vector<int> com : combinations){
                for(int i : com){
                    std::cout << i << " " ;
                }
                std::cout << "\n";
            }
            return combinations;
        }
    private:
        void backTrack(std::vector<std::vector<int>>& combinations, std::vector<int>& candidates, std::vector<int>& path, int target, int indx){
            if(target == 0){
                combinations.push_back(path);
                return;
            }
            if(target < 0){
                return;
            }
            for(int i = indx ; i < candidates.size(); i++){
                if(i > indx && candidates[i] == candidates[i-1])continue;
                path.push_back(candidates[i]);
                backTrack(combinations,candidates,path,target-candidates[i],i+1);
                path.pop_back();
            } 
            return;
        }
};

int main(){
    std::vector<int> candidates = {10,1,2,7,6,1,5};
    Solution solu;
    solu.combinationSum2(candidates,8);
}
