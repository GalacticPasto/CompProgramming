#include <iostream>

long long maximumSubarraySum(int* nums, int numsSize, int k) {
    int minX=0;
    int maxX= 0;
    int minY= 0;
    int maxY= 0;

    for(int i = 0 ; i < array.size() ;i++){
        if(i % 2 == 0){
            minX = std::min(array[i],minX);
            maxX= std::max(array[i],maxX);
        }
        else{
            minY = std::min(array[i],minY);
            maxY = std::max(array[i],maxY);	
        }
    }
}
