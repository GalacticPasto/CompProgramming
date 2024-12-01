#include <iostream>
#include <vector>

class Solution{
    public: 
        bool exist(std::vector<std::vector<char>>& board, std::string word){
            int n = board.size();
            int m = board[0].size();
            
            std::vector<std::vector<bool>> visited(n,std::vector<bool>(m,false));
            
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    if(visited [i][j] == false && board[i][j] == word[0]){
                        if(dfs(board,visited,word,i,j,0)){
                            return true;
                        }
                    }     
                }
            } 

            return false;
        }
    private:
        bool dfs(std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, std::string& word, int i , int j , int indx){
            if(indx == word.size()){
                return true;
            }
            if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] == true || board[i][j] != word[indx]){
                return false;
            }
            
            visited[i][j] = 1;
            
            int left= dfs(board,visited,word,i,j-1,indx+1);
            int right = dfs(board,visited,word,i,j+1,indx+1);
            int up = dfs(board,visited,word,i-1,j,indx+1);
            int down = dfs(board,visited,word,i+1,j,indx+1);

            visited[i][j] = 0;
            
            return left | right | up | down; 
        }

};
