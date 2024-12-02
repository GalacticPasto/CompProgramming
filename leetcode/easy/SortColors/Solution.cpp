#include <iostream>
#include<vector>

void swap(std::vector<int>& nums, int i , int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
void sortArray(std::vector<int>& nums, int n)
{
    // Write your code here
    int i = 0 ; 
    int j = 0;
    int k = n -1;

    for(int i : nums){
        std::cout << i << " ";
    } 
    std::cout << "\n";
    
    while(i <= k){
        if(nums[i] == 0){
            std::swap(nums[j],nums[i]);
            j++;
            i++;
        }
        else if(nums[i] == 1){
            i++;
        }
        else{
            std::swap(nums[k],nums[i]);
            k--;
        }
    }
    for(int i : nums){
        std::cout << i << " ";
    } 
    std::cout << "\n";
}
int main(){
    std::vector<int> flag ={2,2,2,2,0,0,1,0};
    sortArray(flag,flag.size());
}
