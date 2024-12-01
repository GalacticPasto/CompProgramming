#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>

class Solution{
public:
    std::vector<std::vector<int>> fourSumBruteForce(std::vector<int>& nums,int target){ // T(c) -> n^4 * log n // S(c) -> 2n
        int n = nums.size();
        std::vector<std::vector<int>>  ans;
        std::set<std::vector<int>> set;

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                for(int k = j+1 ; k < n ; k++){
                    for(int l = k +1 ; l < n; l++){
                        long long add = nums[i] + nums[j];
                        add += nums[k] + nums[l];
                        if(add == target){
                            std::vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                            std::sort(temp.begin(), temp.end());
                            if(set.find(temp) == set.end()){
                                ans.push_back(temp);
                                set.insert(temp);
                            }
                        }
                    }
                }
            }
        }
        return ans; 
    }
    std::vector<std::vector<int>> fourSumBruteABitOptimized(std::vector<int>& nums,int target){ // T(c) -> n^3 * log n // S(c) -> 2n
        int n = nums.size();
        std::vector<std::vector<int>>  ans;
        std::set<std::vector<int>> set;

        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                std::unordered_set<int> numSet;
                for(int k = j+1 ; k < n ; k++){
                    long long add = nums[i] + nums[j] + nums[k];
                    int fourth = -(add);
                    if(numSet.find(fourth) != numSet.end()){
                        std::vector<int> temp = {nums[i],nums[j],nums[k], fourth};
                        std::sort(temp.begin(), temp.end());
                        if(set.find(temp) == set.end()){
                            ans.push_back(temp);
                            set.insert(temp);
                        }
                        numSet.insert(nums[k]);
                    }
                }
            }
        }
        return ans;
    }

    std::vector<std::vector<int>> fourSumBruteABitIDK(std::vector<int>& nums,int target){ // T(c) -> n^3 // S(c) -> O(1)
        int n = nums.size();

        std::vector<std::vector<int>>  ans;
        std::sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < n ; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            for(int j = i + 1 ; j < n ; j++){
                if(j != i + 1 && nums[j] == nums[j-1])continue;
                
                int k = j + 1;
                int l = n - 1;
                
                while(k < l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target){
                        std::vector<int> vec = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(vec);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k-1])k++;
                        while(k < l && nums[l] == nums[l+1])l--;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};
