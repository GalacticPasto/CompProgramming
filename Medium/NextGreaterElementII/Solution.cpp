#include <iostream>
#include <vector>
#include <stack>

class Solution{
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums){
        int n = nums.size();
        std::vector<int> ans(n,-1);
        std::stack<int> st;         
        
        for(int i = 2 * n - 1 ; i >= 0 ; i--){
            while(!st.empty() && st.top() <= nums[i % n]){
                st.pop();
            }
            if(i < n){
                if(!st.empty()){ans[i] = st.top();}
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
};

int main(){
    Solution solu;
    std::vector<int> nums = {1,2,3,4,3};
    std::vector<int> ans = solu.nextGreaterElement(nums);
    for(int i : ans){
        std::cout << i << "\n";
    }
}
