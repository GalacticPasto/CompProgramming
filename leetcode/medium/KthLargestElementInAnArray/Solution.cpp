#include <iostream>
#include <vector>
#include <queue>

class Solution{
    public:
        int findKthLargestElement(std::vector<int>& nums , int k){
            std::priority_queue<int> q;
            for(int i : nums){
                q.push(i);
            }
            while(k > 1){
                q.pop();
                k--;
            }
            return q.top();
        }
};

int main(){
    std::vector<int> nums ={3,2,3,1,2,4,5,5,6};
    int k = 4;
    Solution solu;
    std::cout << solu.findKthLargestElement(nums,k) << "\n";
}
