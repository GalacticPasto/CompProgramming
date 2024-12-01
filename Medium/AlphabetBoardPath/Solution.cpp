#include <iostream>

void bfs(std::vector<std::vector<char> >& board, std::string& target, std::string& ans, std::string path,int indx , int row, int col)
{
    if(indx == target.size())
    {
        path.pop_back();
        if(ans == "")
        {
            ans = path;
        }
        else
        {
            if(ans.size() > path.size())
            {
                ans = path;
            }
        }
        return;
    } 
    if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] == '#')return;
    while(indx < target.size() && board[row][col] == target[indx])
    {
        indx++;
        path.push_back('!');
    } 
    char temp = board[row][col];
    board[row][col] = '#';

    bfs(board,target,ans,path+'U',indx,row-1,col);
    bfs(board,target,ans,path+'D',indx,row+1,col);
    bfs(board,target,ans,path+'R',indx,row,col+1);
    bfs(board,target,ans,path+'L',indx,row,col-1);
    board[row][col] = temp;

    return;
}

std::string alphabetBoardPath(std::string target) 
{
    std::vector<std::vector<char> > board = 
                                            {{'a','b','c','d','e'},
                                             {'f','g','h','i','j'},
                                             {'k','l','m','n','o'}, 
                                             {'p','q','r','s','t'},
                                             {'u','v','w','x','y'},
                                             {'z','#','#','#','#'}}; 
    std::string ans = "";
    bfs(board,target,ans,"",0,0,0);
    return ans;
}   

int main()
{
    int n = 0;
    std::cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        std::string target;
        std::cin >> target;
        std::cout << alphabetBoardPath(target) << "\n";
    }
}

