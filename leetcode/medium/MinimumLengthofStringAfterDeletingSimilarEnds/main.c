#include <stdio.h>
#include <string.h>

int minimumLength(char *s)
{
    int left = 0;
    int right = strlen(s) - 1;

    while (left < right)
    {
        if (s[left] != s[right])
        {
            break;
        }
        while (left <= right && s[left] == s[right])
        {
            left++;
        }
        while (right >= left && s[left - 1] == s[right])
        {
            right--;
        }
    }

    int ans = right - left + 1;

    return ans;
}

int main()
{
    char *str = "cabaabac";
    int   ans = minimumLength(str);
    printf("%i\n", ans);
}
