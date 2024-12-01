#include <iostream>
#include <vector>

class Solution{
public:
    int numberOfInversions(std::vector<int>& a,int n){
        return split(a,0,n-1); 
    }
private:
    int split(std::vector<int>& a,int start, int end){
        int count = 0;
        if(start >= end)return count;
        int middle = (start + end)/2;
        count += split(a,start,middle);
        count += split(a,middle+1,end);
        count += merge(a,start,middle,end);
        return count;
    }
    int merge(std::vector<int>& a,int start, int middle , int end){
        std::vector<int> tmp;
        int left = start;
        int right = middle + 1;
        int count = 0; 
        while(left <= middle && right <= end){
            if(a[left] <= a[right]){
                tmp.push_back(a[left]);
                left++;
            }
            else{
                tmp.push_back(a[right]);
                count += (middle - left + 1);
                right++;
            }
        }
        while(left <= middle){
            tmp.push_back(a[left]);
            left++;
        }
        while(right <= end){
            tmp.push_back(a[right]);
            right++;
        }
        for(int i = start; i <= end ;i++){
            a[i] = tmp[i - start];
        }
        return count;
    } 
};

int main(){
    Solution solu;
    std::vector<int> a = {4,3,2,1};
    int b = solu.numberOfInversions(a,4);
    std::cout << b << " ";
}
