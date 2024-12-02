#include <iostream>
#include <vector>
#include <unordered_map>
// 1 1 2 3
int findMaxFruits(std::vector<int>& arr){
    int max = 0;
    int n = arr.size(); 
    for(int i = 0 ; i  < n ; i++){
        std::unordered_map<int,int> map;
        for(int j = i ; j < n ;j++){
            if(map.find(arr[j]) != map.end()){
                map[arr[j]] += 1;
            }
            else{
                if(map.size() == 2){
                    break;
                }
                map[arr[j]] = 1;
            }
        }
        int fruits = 0;
        for(std::unordered_map<int,int>::iterator it = map.begin() ; it != map.end() ; it++){
            fruits += it->second; 
        }
        max = std::max(fruits,max);
    }
    return max;
}

int main(){
    std::vector<int> arr = {0,1,6,6,4,4,6};
    std::cout << findMaxFruits(arr) << "\n";
}
