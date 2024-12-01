#include <iostream>
#include <vector>

class Solution{
public:
    void merge(std::vector<int>& nums1, int m , std::vector<int>& nums2 , int n){ // T(c) nlogn + o(n) // S(c) o(1)
        int length = m + n;
        int pointer = m;
        int j = 0; 

        while(j < n && pointer < length){
            nums1[pointer++] = nums2[j++];
        }
        std::sort(nums1.begin(),nums1.end());
        for(int i : nums1){
            std::cout << i << " ";
        } 
        std::cout << "\n";
    }
    void mergeOptimal(std::vector<int>& nums1, int m , std::vector<int>& nums2 , int n){ // T(c) nlogn + o(n) // S(c) o(1)
        int i = m;
        int j = 0;

        while(i >= 0 && j < n){
            if(nums1[i] > nums2[j]){
                std::swap(nums1[i],nums2[j]);
                i--;
                j++;
            }
            else{
                break;
            }
        }
        i = m;
        j = 0;
        while(i < m + n  && j < n){
            nums1[i++] = nums2[j++];
        }
        for(int i : nums1){
            std::cout << i << " ";
        } 
        std::cout <<"\n";
    }
};

int main(){
    std::vector<int> nums1 = {1,2,3,0,0,0};
    std::vector<int> nums2 = {1,2,3};
    Solution solu;
    solu.mergeOptimal(nums1,3,nums2,3);
}
