package ExcelSheetColumnNumber;

public class Solution {
    public static void main(String[] args){
        System.out.println(titleToNumber("ZY"));
    } 
    private static int titleToNumber(String columnTitle){
        int ans = 0; 
        for(int i = 0 ; i < columnTitle.length() ; i ++){
            int temp = columnTitle.toLowerCase().charAt(i) - 'a' + 1;
            ans *= 26;
            ans += temp;
        }
        return ans;
    }
}
