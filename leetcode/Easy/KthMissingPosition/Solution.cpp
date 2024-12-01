#include <iostream>
#include <vector>
#include <unordered_set>
class Solution{
public:
    int findKthPositive(std::vector<int>& arr, int k){
        std::unordered_set<int> set;

        int range = arr.size()+k;
        
        for(int i = range ; i >= 1; i--){
            set.insert(i);
        }
        for(int i = 0 ; i < arr.size() ;i++){
            if(set.find(arr[i]) != set.end()){
                set.erase(set.find(arr[i]));
            }
        }
        int count =0;
        int ans = 0;
        for(std::unordered_set<int>::iterator it = set.begin(); it != set.end() ; it++){
            count++;
            if(count == k)ans = *it;
        }
        return ans;
    }
};
int main(){
    Solution solu;
    std::vector<int> arr = {2,3,4,7,11};
    std::cout << solu.findKthPositive(arr,5) << "\n";
}
