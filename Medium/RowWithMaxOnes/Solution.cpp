#include <iostream>
#include <vector>

class Solution{
public:
    int rowWithMaxOnes(std::vector<std::vector<int>>& matrix,int n, int m){
        int ans = -1;
        int maxCount = 0; 
        for(int i = 0 ; i < n ; i++){
            int count = 0;
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 1){
                    count++;
                }
            }
            if(count > maxCount){
                ans = i;
                maxCount = count;
            } 
        }
        return ans;
    }
    int rowWithMaxOnesOptimized(std::vector<std::vector<int>>& matrix,int n, int m){
        int ans = -1;
        int maxCount = 0; 
        for(int i = 0 ; i < n ; i++){
            int count = 0;
            int low = 0;
            int high = m -1;
            while(low <= high){
                int mid = (low + high)/2;
                if(matrix[i][mid] == 1 && matrix[i][mid-1] == 0){
                    count += m - mid;
                    break;
                }
                else if(matrix[i][mid] == 1){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
            if(count > maxCount){
                ans = i;
                maxCount = count;
            }
        }
        return ans;
    }
};

int main(){
    std::vector<std::vector<int>> matrix = {{1,1,1},{0,0,0},{0,0,0}};
    Solution solu;
    std::cout << solu.rowWithMaxOnesOptimized(matrix,3,3) << "\n";
}
