#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> bitManipulation(int num,int i){
    std::vector<int> ans;
    
    int mask = 1;
    while(i-- > 1){
        mask = mask << 1;
    }
    int a = num & mask;
    if(a == 0){
        ans.push_back(0);
        ans.push_back(num | mask);
        ans.push_back(num);
    }
    else{
        ans.push_back(1);
        ans.push_back(num);
        ans.push_back(num ^ mask);
    }
    return ans; 
}
void display(std::vector<int>& num){
    for(int i : num){
        std::cout << i << " "; 
    }
    std::cout << "\n";
}
int main(){
    int n;
    int x;
    std::cout << "the number" << "\n";
    std::cin >> n;
    std::cout << "the ith position" << "\n";
    std::cin >> x;
    std::vector<int> a= bitManipulation(n,x);
    display(a);
}
