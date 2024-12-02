int maxSubArray(int* nums, int numsSize) 
{
    int ans = 0;
    int max = INT_MIN; 
    for(int i = 0 ; i < numsSize ; i++)
        ans += *(nums+i);
        if(*(nums+i) > ans)
        {
            ans = *(nums+i);
        }
        if(ans > max)
        {
            max = ans;
        }
    }
    return ans;     
}
int main()
{

}
