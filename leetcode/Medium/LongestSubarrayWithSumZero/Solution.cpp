#include <iostream>
#include <vector>
#include <unordered_map>

class Solution{
public:
    int getLongestSubarrayWithSumZero(std::vector<int>& arr){
        int n = arr.size();

        std::unordered_map<int,int> map;
        int max = 0;    
        int sum = 0; 

        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(sum == 0){
                max = i + 1;
            }
            else {
                if(map.find(sum) != map.end()){
                    max = std::max((i - map[sum]),max); 
                }else{
                    map[sum] = i;
                }
            }
        }
        return max;
    }
};

int main(){
    Solution solu;
    std::vector<int> vec = {1,-1,0,0,1};
    solu.getLongestSubarrayWithSumZero(vec);
}
