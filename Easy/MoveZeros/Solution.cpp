#include <iostream>
#include <vector>

void moveZeros(std::vector<int>& nums){
    int pointer = 0;
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[pointer] != 0){
            pointer++;
        }
        if(nums[i] != 0 && nums[pointer] == 0){
            int temp = nums[i];   
            nums[i] = nums[pointer];
            nums[pointer] = temp;
            pointer++;
        }
    }
    for(int i : nums){
        std::cout << i << " ";
    }
    std::cout <<"\n";
}

int main(){
    std::vector<int> nums = {4,0,3,2,5};
    moveZeros(nums);
}
