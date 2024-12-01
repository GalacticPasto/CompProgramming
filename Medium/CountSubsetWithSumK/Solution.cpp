#include <iostream>

int modulo = 1e9 + 7;

void dfs(std::vector<int>& arr, int k,int i,int* ans)
{
    if(i == 0)
    {
        if(arr[i] == k)
        {
             (*ans)++;
        }
        return;
    }
    if(k == 0)
    {
        (*ans)++;
        return;
    }
    dfs(arr,k,i-1,ans);
    if(arr[i] <= k)
    {
        dfs(arr,k-arr[i],i-1,ans);
    }
    return;
}

int findWays(std::vector<int>& arr, int k)
{
    int n = arr.size();
    int ans = 0;
    int* pAns = &ans;
    for(int i = n-1 ; i >= 0 ; i--)
    {
        if((i == 0 || i == n-1)&& arr[i] == k)
        {
            ans++;
        }
        else
        {
            if(arr[i] <= k)
            {
                dfs(arr,k-arr[i],n-1,pAns);
            }
        }
    }
    return ans % modulo;
}
