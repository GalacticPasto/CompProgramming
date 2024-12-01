#include <iostream>

std::string customSortString(std::string order, std::string s)
{
    std::unordered_map<char,int> map;
    std::string ans = ""; 
    for(int i = 0 ; i < s.size() ; i++)
    {
        map[s[i]]++;
    }

    for(int i = 0 ; i < order.size() ; i++)
    {
        if(map.find(order[i]) != map.end())
        {
            int n = map[order[i]];
            while(n--)
            {
                ans.push_back(order[i]); 
            }
            map.erase(order[i]);
        }
    }

    for(std::unordered_map<char,int>::iterator it = map.begin(); it != map.end(); it++)
    {
        ans.push_back(it->first);
    }
    std::cout << ans << "\n";
    return ans;
}
