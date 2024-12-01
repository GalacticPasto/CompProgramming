#include <iostream>

int main()
{
    for(int i = 0 ; i < INT_MAX ; i++)
    {
        int temp = i;
        int ones = 0;
        int zeros = 0;

        while(temp)
        {
            if(temp & 1)
            {
                ones++;
            }
            else
            {
                zeros++;
            }
            temp = temp >> 1;
        }
        if(ones == zeros)
        {
            std::cout << i << ",";
        }
    } 
}
