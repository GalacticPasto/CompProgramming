#include <iostream>
#include <vector>

class Solution{
public:
    int upperBound(std::vector<int>& arr,int n , int target){
        return binarySearch(arr,0,n-1,target,n); 
    }
private:
    int binarySearch(std::vector<int>& arr , int low , int high,int target,int ans){

        int i = low;
        int j =high;
    
        while(i <= j){
            int mid = (i + j) / 2;

            if(arr[mid] > target){
                ans = mid;
                j = mid -1;
            }
            else {
                i = mid + 1;
            }
        }
    return ans; 
    }
};
