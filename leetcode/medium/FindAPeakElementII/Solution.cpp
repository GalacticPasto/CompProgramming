#include <iostream>
#include <vector>

class Solution{
public:
    std::vector<int> findPeakGrid(std::vector<std::vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();
        
        int low = 0;
        int high = m -1;

        while(low <= high){
            int mid = (low + high)/2;
            int row = maxFromColumn(mat,mid);
            int left = (mid - 1 < 0 ? -1 : mat[row][mid-1]);
            int right = (mid + 1 < 0 ? -1 : mat[row][mid+1]);
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }
            else if(mat[row][mid] > mat[row][mid+1]){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return {};
    }
private:
    int maxFromColumn(std::vector<std::vector<int>>& mat, int column){
        int max = 0;
        int indx = 0;
        for(int i = 0; i < mat.size() ; i++){
            if(mat[column][i] > max){
                max =mat[column][i]; 
                indx = i;
            }
        }
        return indx;
    }
};

int main(){
    std::vector<std::vector<int>> matrix = {{1,4},{3,2}};
    Solution solu;
    std::vector<int> ans = solu.findPeakGrid(matrix);
    for(int i : ans){
        std::cout << i << " ";
    }
    std::cout << "\n";
}
