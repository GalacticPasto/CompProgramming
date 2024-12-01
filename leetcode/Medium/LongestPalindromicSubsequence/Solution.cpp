#include <iostream>
int maxSize = 0;

bool isPalindrome(std::string& s)
{
    int left = 1;
    int i = s.size()-2;
    while(left <= i)
    {
        if(s[left] != s[i])return false;
        left++;
        i--;
    }
    return true;
}
void dfs(std::string& s, std::string path, int i)
{
    if(i == s.size())
    {
        if(isPalindrome(path))
        {
            maxSize = std::max((int)path.size()+1,maxSize);
        }
        return;
    }
    dfs(s,path,i++);
    path.push_back(s[i]);
    if(path.size() > 1){
        int size = path.size();
        if(path[0] == path[size-1])
        {
                bool take = isPalindrome(path);
                if(take)maxSize = std::max((int)path.size()+1,maxSize);
        }
    }
    std::cout << path << "\n";
    dfs(s,path,i++);
    return;
}
int longestPalindromeSubseq(std::string& s) {
    std::string path = "";
    dfs(s,path,0); 
    return maxSize;
}

int main()
{
    std::string s = "bbbab";
    std::cout << longestPalindromeSubseq(s);
}
