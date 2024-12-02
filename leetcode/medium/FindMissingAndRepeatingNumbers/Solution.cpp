#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> findMissingRepeatingNumbers(std::vector<int>& a){
    int n = a.size();

    long long s = 0;
    long long sN = (n * (n +1))/2;
    long long sSquared = 0;
    long long sNsquared = (n *(n + 1) * (2*n + 1))/6;
    
    for(int i : a){
        s+=i;
        sSquared += (i*i);
    } 

    long long eq1 = s - sN;
    long long eq2 = (sSquared - sNsquared)/eq1;
    
    int x = (eq1 + eq2)/2;
    int y = x - eq1; 
    return{x,y};
}

int main(){
    std::vector<int> a = {1,2,3,2};
    std::vector<int> ans = findMissingRepeatingNumbers(a);
    for(int i : ans){
        std::cout << i << " ";
    }
    std::cout << "\n";
}
