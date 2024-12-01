#include <iostream>
#include <vector>

class Solution{
public:
    int lowerBound(std::vector<int>& arr,int n , int target){
        return binarySearch(arr,0,n-1,target,n); 
    }
private:
    int binarySearch(std::vector<int>& arr , int low , int high,int target,int ans){

        int i = low;
        int j =high;
    
        while(i <= j){
            int mid = (i + j) / 2;

            if(arr[mid] >= target){
                ans = mid;
                int a =  std::min(binarySearch(arr,i,mid-1,target,ans),ans);
                ans = std::min(a,ans);
                j = mid -1;
            }
            else if(arr[mid] <= target){
                int a = std::min(binarySearch(arr,mid+1,j,target,ans),ans);
                ans = std::min(a,ans);
                i = mid + 1;
            }
        }
    return ans; 
    }
};

int main(){
    Solution solu;
    std::vector<int> arr = {1,2,2,3};
    int ans = solu.lowerBound(arr,arr.size(),0);
    std::cout << ans << "\n";
}
