#include <iostream>
#include <vector>


class Solution{
public:
    int trap(std::vector<int>& height){
        int n = height.size();
        int ans = 0; 
        int left =1;
        int right = n-1;
        int leftMax = height[0]; 
        int rightMax= height[n-1]; 
    
        while(left <= right){
            if(height[left] <= height[right]){
                if(height[left] >= leftMax){
                    leftMax = height[left];
                }
                else{
                    ans += leftMax - height[left];
                }
                left++;
            }
            else{
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }
                else{
                    ans += rightMax - height[right];
                }
                right--;
            }
        } 
        return ans; 
    }
};

int main(){
    Solution solu;
    std::vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << solu.trap(height) << "\n";
}
