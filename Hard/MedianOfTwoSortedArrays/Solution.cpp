#include <iostream>
#include <vector>

class Solution{
public:
    double findMedianOfTwoSortedArrays(std::vector<int>& nums1,std::vector<int>& nums2){ // o(n+m) same for space and time
        int n = nums1.size();
        int m = nums2.size();
        std::vector<int> merged;
        int i = 0;
        int j = 0;
        while(!nums1.empty() && !nums2.empty() &&  i < n && j < m){
            if(nums1[i] <nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
            else{
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while(!nums1.empty() && i < n){
            merged.push_back(nums1[i]);
            i++;
        }
        while(!nums2.empty() && j < m){
            merged.push_back(nums2[j]);
            j++;
        }
        int k = merged.size();
        if(k % 2 == 1){
            return (double)merged[k/2];
        }
        return (((double)merged[k/2] + (double)(merged[(k/2)-1]))/2);
    } 
    double findMedianOfTwoSortedArraysSpaceOptimized(std::vector<int>& nums1,std::vector<int>& nums2){ // o(n+m) same for space and time
        int n = nums1.size();
        int m = nums2.size();
        int k = n + m; 
        
        int ind1 = k/2;
        int ind2 = (k/2)-1;
        int ele1 = 0;
        int ele2 = 0;

        int i = 0;
        int j = 0;
        int count = 0;
        while(!nums1.empty() && !nums2.empty() &&  i < n && j < m){
            if(nums1[i] < nums2[j]){
                if(count == ind1)ele1 = nums1[i];
                if(count == ind2)ele2 = nums1[i];
                count++;
                i++;
            } 
            else{
                if(count == ind1)ele1 = nums2[j];
                if(count == ind2)ele2 = nums2[j];
                count++;
                j++;
            }
        }
        while(!nums1.empty() && i < n){
            if(count == ind1)ele1 = nums1[i];
            if(count == ind2)ele2 = nums1[i];
            count++;
            i++;
        }
        while(!nums2.empty() && j < m){
                if(count == ind1)ele1 = nums2[j];
                if(count == ind2)ele2 = nums2[j];
                count++;
                j++;
        }
        if(k % 2 == 1){
            return ele1;
        }
        return (double)(ele1 + ele2)/2;
    }

    double findMedianOfTwoSortedArraysOptimal(std::vector<int>& nums1,std::vector<int>& nums2){ // o(n+m) same for space and time

        return 0.0;
    }

};
int main(){
    Solution solu;
    std::vector<int> nums1 = {1,3};
    std::vector<int> nums2 = {2,4};
    std::cout << solu.findMedianOfTwoSortedArrays(nums1,nums2) << "\n";
    std::cout << solu.findMedianOfTwoSortedArraysSpaceOptimized(nums1,nums2) << "\n";
}
