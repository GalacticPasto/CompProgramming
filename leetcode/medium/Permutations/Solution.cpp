#include <iostream>
#include <vector>

class Solution{
<<<<<<< HEAD
    public:
        std::vector<std::vector<int>> permute(std::vector<int>& nums){
            std::vector<std::vector<int>> permutations;
            generatePermutations(permutations,nums,0);
            for(std::vector<int> perm : permutations){
                for(int i : perm){
                    std::cout << i << " " ;
                }
                std::cout << "\n";
            }
            return permutations;
        }
    private:
        void generatePermutations(std::vector<std::vector<int>>& permutations, std::vector<int>& nums,int i){
            if(i == nums.size()-1){
                permutations.push_back(nums);
            }    
            for(int j = i ; j <nums.size(); j++){
                std::swap(nums[i],nums[j]);
                generatePermutations(permutations, nums, i+1);
                std::swap(nums[i],nums[j]);
            }
        }
=======
    public: 
        std::vector<std::vector<int>> permute(std::vector<int>& nums){
            if(nums.size() <= 1){
                return {nums};
            }
            std::vector<std::vector<int>> ans;
            for(int i = 0 ; i < nums.size(); i++){
                std::vector<int> oneLess(nums.begin() , nums.end());
                oneLess.erase(oneLess.begin()+i);
                auto res = permute(oneLess);

                for(int j = 0 ; j < res.size(); j++){
                    std::vector<int> final = res[j]; 
                    final.insert(final.begin(),nums[i]); 
                    ans.push_back(final);
                }
            }
            return ans;
        }



>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
};

int main(){
    std::vector<int> nums = {1,2,3};
    Solution solu;
<<<<<<< HEAD
    solu.permute(nums);
}
=======
    std::vector<std::vector<int>> ans = solu.permute(nums);
    std::cout << " hello " << std::endl;
    for(std::vector<int> list : ans){
        for(int i : list){
            std::cout << i << " " << std::endl;
        }
        std::cout << " " << std::endl;
    }
};
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
