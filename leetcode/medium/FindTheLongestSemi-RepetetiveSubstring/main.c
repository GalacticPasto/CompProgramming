#include <stdio.h>
#include <string.h>

int longestSemiRepetitiveSubstring(char *s)
{
    int length = strlen(s);

    int left = 0;
    int right = 1;
    int flag = 0;

    int ans = 0;
    while (left < right && right < length)
    {
        while (flag && s[right - 1] == s[right])
        {
            left++;
            if (s[left - 1] == s[left])
            {
                flag = 0;
            }
        }
        if (s[right - 1] == s[right])
        {
            flag = 1;
        }
        right++;
        int lenWindow = right - left;
        ans = (lenWindow > ans) ? lenWindow : ans;
    }
    int lenWindow = right - left;
    ans = (lenWindow > ans) ? lenWindow : ans;
    return ans;
}

int main()
{

    int ans = longestSemiRepetitiveSubstring("52233");
    printf("%i\n", ans);
}
