#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<std::vector<int>> combine(int n, int k){
            std::vector<std::vector<int>> combinations;
            std::vector<int> combination; 
            std::vector<int> range;
            for(int i = 1 ; i <= n ; i++){
                range.push_back(i);
            }
            backTrack(combinations,combination,range,k,0); 
            for(std::vector<int> com : combinations){
                for(int i : com){
                    std::cout << i << " "; 
                }
                std::cout << "\n";
            }
            return combinations;
        }
    private:
        void backTrack(std::vector<std::vector<int>>& combinations, std::vector<int>& combination, std::vector<int>& range,int k,int indx){
            if(combination.size() == k){
                combinations.push_back(combination);
                return;
            }
            for(int i = indx ; i < range.size() ; i++){
                combination.push_back(range[i]);
                backTrack(combinations,combination,range,k,i+1);
                combination.pop_back();
            }
            return;
        }

};

int main(){
    Solution solu;
    solu.combine(4,2);
}
