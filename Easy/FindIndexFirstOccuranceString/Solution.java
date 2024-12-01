package FindIndexFirstOccuranceString;

public class Solution {
    public static void main(String[] args) {
        System.out.println(strStr("abccdedeededfg", "dedfg"));
    }

    private static int strStr(String haystack, String needle) {
        int i = 0;
        int j = 0;
        while (i < haystack.length() && j < needle.length()) {
            Character c = haystack.charAt(i);
            if (c.equals(needle.charAt(j))) {
                j++;
            } else if (j > 0) {
                i = i - j;
                j = 0;
            }
            i++;
            if (j == needle.length()) {
                return i - j;
            }
        }
        return j;
    }

    private static int kmp(String haystack, String needle) {
        int i = haystack.length();
        int j = needle.length();

        return -1;
    }

    private void lpsArray(String pattern, int M, int[] lps) {
        int len = 0;
        int i = 1;
        lps[0] = 0;

        while (i < M) {
            if (pattern.charAt(i) == pattern.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = len;
                    i++;
                }
            }
        }
    }
}
