#include <iostream>

int findCircleNum(std::vector<std::vector<int>>& isConnected) 
{
    int ans = 0; 
    std::unordered_set<std::pair<int,int>> set1;    

    for(int i = 0 ; i < isConnected.size() ; i++)
    {
        if(isConnected[i][2] == 0)
        {
            set1.insert({isConnected[i][0],isConnected[i][1]});
        }
        else
        {
            ans++;
        }
    }

    ans += set1.size();
    return ans;
}
