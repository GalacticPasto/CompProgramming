#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

class Solution{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums){ // T(c) -> O(n^3 * log m) S(c) -> 2*O(n) one for set,one for the no of triplets
        std::set<std::vector<int>> mySet;

        int n = nums.size(); 
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                for(int k = j + 1 ; k < n ; k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        std::vector<int> temp = {nums[i],nums[j],nums[k]};
                        std::sort(temp.begin(), temp.end());
                        if(mySet.find(temp) == mySet.end()){
                           mySet.insert(temp); 
                        }
                    }
                }
            }
        }
        std::vector<std::vector<int>> ans(mySet.begin(), mySet.end());  
        return ans;
    } 
    std::vector<std::vector<int>> threeSumOptimized(std::vector<int>& nums){ // T(c) -> O(n^2)avg O(n^2 * log m) S(c) -> 2*O(n) one for set,one for the no of triplets

        std::set<std::vector<int>> mySet;
        int n = nums.size(); 
        for(int i = 0 ; i < n ; i++){
            std::unordered_set<int> set;
            for(int j = i+1 ; j < n ; j++){
                int third = -(nums[i] + nums[j]);
                if(set.find(third) != set.end()){
                    std::vector<int> temp = {nums[i],nums[j],third};
                    std::sort(temp.begin(), temp.end());
                    mySet.insert(temp);
                }
                else{
                    set.insert(nums[j]);
                }
            }
        }
        std::vector<std::vector<int>> ans(mySet.begin(), mySet.end());  
        return ans;
    } 
    std::vector<std::vector<int>> threeSumOptimal(std::vector<int>& nums){ // T(c) -> O(n^2 + nlogn) S(c) -> O(n) for the no of triplets
        int n = nums.size();
        
        std::sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> ans;   

        int j = 0;
        int k = n-1;
        for(int i = 0 ; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            j = i+1;
            while(j < k){
                int add = nums[i] + nums[j] + nums[k];
                if(add < 0){
                    j++;
                }
                else if(add > 0){
                    k--;
                }
                else{
                    std::vector<int> vec = {nums[i],nums[j],nums[k]};
                    ans.push_back(vec);            
                    j++;
                    k--;
                    while(nums[j] == nums[j-1])j++;
                    while(nums[k] == nums[k+1])k--;
                }
            }
        }

        return ans; 
    } 

private:
    void generateSubarrays(std::vector<int>& nums){

    }
    void display(std::vector<std::vector<int>>& ans){
        for(int i = 0 ; i < ans.size(); i++){
            for(int j = 0; j < 3 ; j++){
                std::cout << ans[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main(){
    std::vector<int> nums = {-1,0,1,2,-1,-4};
    Solution solu;
    solu.threeSum(nums);
}
