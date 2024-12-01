#include <iostream>
#include <vector>

int rangeSum(std::vector<int>& nums, int n, int left, int right) 
{
    std::vector<long long > subarraySum;

    for(int i = 0 ; i < n ; i++)
    {
        long long sum = 0;
        for(int j = i ; j < n ; j++)
        {
            sum += nums[j];
            subarraySum.push_back(sum);
        }
    }
    std::sort(subarraySum.begin(),subarraySum.end());
    long long sum = 0;
    for(int i = left - 1 ; i < right ; i++)
    {
        sum += subarraySum[i];
        //std::cout << sum << "\n";
    }
    return sum;
}

int main()
{
    int n = 0;
    int left = 0;
    int right = 0;
    std::vector<int> nums(n,0);
    std::cin >> n; 
    std::cin >> left; 
    std::cin >> right; 
    
    for(int i = 0 ; i < n ; i++)
    {
        int a = 0;
        std::cin >> a;
        nums[i] = a;
    }
    std::cout << rangeSum(nums,n,left,right) << "\n";
}
