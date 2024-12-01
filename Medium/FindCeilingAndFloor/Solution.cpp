#include <iostream>
#include <vector>

std::pair<int,int> getFloorAndCeil(std::vector<int>& a ,int n , int target){
    
    int low = 0;
    int high = n-1;
    int first = -1; 
    
    // floor
    while(low <= high){
        int mid = (low + high)/2;
    
        if(a[mid] <= target){
            first = a[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    //ceiling 
    low = 0;
    high = n -1;
    int second = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(a[mid] > target) {
            second = a[mid]; 
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return{first,second};
}
