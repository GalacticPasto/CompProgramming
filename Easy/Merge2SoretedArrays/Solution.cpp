#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int>& a , std::vector<int>& b){
    int pA = 0;
    int pB = 0;
    std::vector<int> arr;
    while (pA < a.size() && pB < b.size()) {
      if (a[pA] < b[pB]) {
          arr.push_back(a[pA]);
          pA++;
      } 
      else if(a[pA] == b[pB]){
          arr.push_back(a[pA]);
          pA++;
          pB++;
      }
      else{
          arr.push_back(b[pB]);
          pB++;
      }
    }
    while (pA < a.size()) {
        arr.push_back(a[pA]);
        pA++;
    } 
    while (pB < a.size()) {
        arr.push_back(b[pA]);
        pB++;
    }
    return arr;
}

int main(){
    std::vector<int> a = {1,2,3,4,6};
    std::vector<int> b = {2,3,5};
    std::vector<int> ans = merge(a,b);
    for(int i : ans){
        std::cout << i << " ";
    }
    std::cout << "\n";
}
