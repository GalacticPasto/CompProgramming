#include <iostream>
#include <iterator>
#include <vector>

class Solution{
    public:
        std::vector<std::vector<int>> combinationSum3(int k , int n){
            std::vector<std::vector<int>> combinations;
            std::vector<int> combination;
            std::vector<int> range;
            for(int i = 1 ; i < 10 ; i++){
                range.push_back(i);
            }
            backTrack(combinations,combination,range,k,n,0);
            for(std::vector<int> com : combinations){
                for(int i : com){
                    std::cout << i << " ";
                }
                std::cout << "\n";
            }
            return combinations;
        }
    private:
        void backTrack(std::vector<std::vector<int>>& combinations, std::vector<int>& combination, std::vector<int>& range, int size , int target , int indx){
            if(target == 0 && combination.size() == 3){
                combinations.push_back(combination);
                return;
            }
            if(target < 0 || combination.size() > size)return;
            for(int i = indx ; i < range.size() ; i++){
                combination.push_back(range[i]);
                backTrack(combinations,combination,range,size,target-range[i],i+1);
                combination.pop_back();
            }
            return;
        }
};
int main(){
    Solution solu;
    solu.combinationSum3(3,7);
}
