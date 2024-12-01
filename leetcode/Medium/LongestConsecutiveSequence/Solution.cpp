#include <iostream>
#include <vector>
#include<unordered_set>

class Solution {
    public:
        int longest(std::vector<int> &nums) {
            std::unordered_set<int> set;
            for(int i : nums){
                set.insert(i);
            }
            int counter = 0;
            for(int i : nums){
                if(set.find(i-1) != set.end()){
                   continue; 
                }
                int local = 1;
                int j = i;
                while(set.find(j+1) != set.end()){
                    local++;
                    j++;
                }
                counter = std::max(local,counter);
            }
            return counter;
        }
};

int main(){
    std::vector<int> nums ={1,100,200,300,5,3,4,2};
    Solution solu;
    int ans = solu.longest(nums);
    std::cout << ans << "\n";
}
