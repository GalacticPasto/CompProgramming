#include <iostream>
#include <vector>
<<<<<<< HEAD

int helper(std::vector<int>& height,int n , int k , int indx){
    if(indx == 0){
        return 0;
    }
    int cost = 0;
    for(int i = 1 ; i <= k ; i++){
        cost = INT_MAX;
        if(indx - i > 0){
            int jump = helper(height,n,k,indx-i) + std::abs(height[indx -i] - height[i]);
            cost = std::min(jump,cost);
        }
    }
    return cost;    
}


int minimalCost(int n , int k , std::vector<int>& height){
    return helper(height,n,k,1);
=======
#include <climits>


int helper(std::vector<int>& height, int k,int indx){
    if(indx == 0){
        return 0;
    }
    int minCost;
    for(int i = 1 ; i < height.size(); i++){
        minCost = INT_MAX;
        for(int j = 1 ;j <= k ; j++){
            if(i - j > 0){
                int cost = helper(height,k,i-j) + std::abs(height[i]-height[j]);
                minCost = std::min(cost,minCost);
            } 
        } 
    }
    return minCost;
}
int minimizeCost(int n , int k , std::vector<int>& height){  
    int cost = helper(height,k,n-1);
    return cost;
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
}

int main(){
    std::vector<int> height = {10,40,30,10};
<<<<<<< HEAD
    std::cout << minimalCost(height.size(),2,height)<< "\n";
=======
    int res = minimizeCost(height.size(),2 , height);
    std::cout << res << "\n";
>>>>>>> 17c12971aea15d7e3a2b5a5ce8c290f088aba456
}
