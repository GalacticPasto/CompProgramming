#include <iostream>
#include <vector>

class Solution{
public:
    int myAtoi(std::string s){
        bool isNeg = false;
        unsigned long long ans = 0;
        int i = 0;

        while(s[i] == ' ')i++;
        if(s[i] == '-'){
            isNeg = true;
            i++;
        }
        else if(s[i] == '+' && !isNeg)i++;
        while(s[i] >= '0' && s[i] <= '9'){
            ans = ans*10 + (s[i] - '0');
            i++;
            if(ans > INT_MAX)break;
        }
        if(isNeg && ans > INT_MAX)return INT_MIN;
        else if(ans > INT_MAX)return INT_MAX;
        return (isNeg ? ans*-1 : ans);
    }
};
