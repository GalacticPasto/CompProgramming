#include <iostream>
#include <vector>

class Solution{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0 ; i < n ; i++){
            if(target >= matrix[i][0] && target <= matrix[i][m-1]){
                if(binarySearch(matrix[i],target)){
                    return true;
                } 
            }
        }
        return false;
    }
    bool searchMatrixOptimized(std::vector<std::vector<int>>& matrix, int target){
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = 0;
        int column = m-1;

        while(row <= column){
            if(matrix[row][column] == target)return true;
            else if(matrix[row][column] > target){ row--;}
            else {column++;}
        }
        return false;
    }
private:
    bool binarySearch(std::vector<int>& array , int target){
        int low = 0;
        int high = array.size()-1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(array[mid] == target){
                return true;
            }
            else if(array[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return false;
    }
};

int main(){
    std::vector<std::vector<int>> ans = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    Solution solu;
    std::cout << solu.searchMatrix(ans,20) << "\n";
}
