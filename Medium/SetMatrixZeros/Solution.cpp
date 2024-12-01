#include <iostream>
#include <vector>

class Solution{
    public:
        void setZeros(std::vector<std::vector<int>>& matrix){
            int n = matrix.size();
            int m = matrix[0].size();

            int row[n];
            int column[m];
            memset(row,0,sizeof(row)); 
            memset(column,0,sizeof(column)); 

            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(matrix[i][j] == 0){
                        row[i] = 1;
                        column[j] = 1;
                    }
                }
            }
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(row[i] == 1 || column[j] == 1){
                        matrix[i][j] = 0;
                    }
                }
            }
        }
};

int main(){
    std::vector<std::vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution solu;
    solu.setZeros(matrix);
}
