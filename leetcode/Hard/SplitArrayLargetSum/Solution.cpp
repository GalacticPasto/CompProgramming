#include <iostream>
#include <vector>
#include <numeric>

class Solution{
public:
    int splitArray(std::vector<int>& nums,int k){
        int min = *(std::max_element(nums.begin(),nums.end()));
        int max = std::accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        for(int i = min ; i <= max; i++){
            bool possible = isPossible(nums,k,i);

            if(possible){
                continue; 
            }else{
                ans = i;
                break;
            }
        }
        return ans;
    }
private:
    bool isPossible(std::vector<int>& nums,int noOfSplits,int eachSplitMaxSum){
        int sum = 0;
        int count = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(sum + nums[i] > eachSplitMaxSum){
                count++;
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        return (count >= noOfSplits);
    }
};
int main(){
    std::vector<int> nums = {7,2,5,10,8};
    Solution solu;
    std::cout << solu.splitArray(nums,2) << "\n";
}
