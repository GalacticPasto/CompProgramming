#include <iostream>
#include <vector>
#include <unordered_map>
class Solution{
public:
    std::vector<int> majorityElement(std::vector<int>& nums){
        std::vector<int> ans;
        
        int ele1 = 0;
        int count1 = 0;
        int ele2 = 0;
        int count2 = 0;

        for(int i : nums){
            if(ele1 == 0 && i != ele2){
                ele1 = i;
            }
            else if(ele2 == 0 && i != ele1){
                ele2 = i;
            }
            else if(i == ele1){
                count1++;
            }
            else if(i == ele2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        int min = nums.size()/3;
        int cnt1, cnt2 = 0;
         
        for(int i : nums){
            if(i == ele1)cnt1++;
            if(i == ele2)cnt2++;
        }
        if(cnt1 >= min)ans.push_back(ele1);
        if(cnt2 >= min)ans.push_back(ele2);
        return ans;
    }
};
