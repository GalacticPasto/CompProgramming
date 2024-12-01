#include <iostream>
#include <vector>

class Solution{
    int noOfPaths = 0;
    public: 
        int uniquePaths(int m, int n){
            std::vector<std::vector<int>> grid(m,std::vector<int>(n,0));

            return noOfPaths;
        }
};
int main(){
    Solution solu;
    int i = solu.uniquePaths(3,7);
    std::cout << i << std::endl;
}
