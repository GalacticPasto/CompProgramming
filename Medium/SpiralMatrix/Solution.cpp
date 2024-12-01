#include <iostream>
#include <vector>

class Solution{
    public:
        std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix){
            std::vector<int> ans;
            
            int i = 0;
            int top = 0;
            int bottom = 0;
            int row = matrix.size(); 
            int column= matrix[0].size();
            while(top < row && bottom < column){ 
            for(i = top ; i < column; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(i = top ; i < row; i ++){
                ans.push_back(matrix[i][column-1]);
            } 
            column--; 
            if(top < row){
                for(i = column-1; i >= bottom ; i--){
                    ans.push_back(matrix[row-1][i]);
                }
                row--;
            }
            if(bottom < column){
                for(i = row -1 ; i >= top ; i--){
                    ans.push_back(matrix[i][bottom]);
                } 
                bottom++;
            }
        }
        return ans;
        }
    private:
        void display(std::vector<std::vector<int>>& matrix){
            for(std::vector<int> row : matrix){
                for(int i : row){
                    std::cout << i << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }
};

int main(){
    std::vector<std::vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    Solution solu;
    std::vector<int> ans;
    ans = solu.spiralOrder(matrix);
    for(int i : ans){
        std::cout << i << " ";
    }
    std::cout << "\n";
}
