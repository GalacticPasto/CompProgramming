#include <vector>
#include <iostream>
// 5 2 10 4  // 0 1
std::vector<int> countGreaterElements(std::vector<int>& arr, std::vector<int>& query){
    int q = query.size(); 
    std::vector<int> ans(q,-1);    
    for(int i = q-1; i >= 0; i--){
        int count = 0;
        for(int j = i+1 ; j < arr.size() ; j++){
            if(arr[j] > arr[i])count++;
        } 
        ans[i] = count;
    }
    for(int i : ans){
        std::cout << i << "\n";
    }
    return ans;
}

int main(){
    std::vector<int> arr = {5,2,10,4};
    std::vector<int> query= {0,1};
    countGreaterElements(arr,query);
}
