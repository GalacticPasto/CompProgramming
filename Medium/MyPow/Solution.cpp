#include <iostream>
#include <vector>
#include <cmath>
class Solution{
public:
    double myPow(double x,int n){
        double ans = x;
        for(int i = 1 ; i < n ; i++){
            ans = pow(ans,x); 
        }
        return ans;
    }
private:
    double pow(double result,int num){
        return result*num; 
    }
};

int main(){
    double num;
    int pow;
    std::cin >> num;
    std::cin >> pow;
    Solution solu;
    std::cout << solu.myPow(num,pow) << "\n";
}
