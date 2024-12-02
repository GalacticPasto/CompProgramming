#include <iostream>
#include <vector>

class Solution{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0 ; i < n ; i++){
            if(target < matrix[i][m-1]){
                int low = 0;
                int high = m - 1;
                while(low <= high){
                    int mid = (low + high)/2;
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    else if(matrix[i][mid] < target){
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
            }
        } 
        return false;
    }
    bool searchMatrixOptimal(std::vector<std::vector<int>>& matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = (n * m) -1;
        
        while(low <= high){
            int mid = (low + high)/2;
            int row = mid / m;
            int column = mid % m;
            if(matrix[row][column] == target){
                return true;
            }
            else if(matrix[row][column] < target){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return false;
};

int main(){
    std::vector<std::vector<int>> ans = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    Solution solu;
    std::cout << solu.searchMatrix(ans,3) << "\n";
}
