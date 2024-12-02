package ExcelColumnSheetTitle;

public class Solution {
    public static void main(String[] args){
        int n = 701;
        System.out.println(convertTOTitle(n));
    }
    private static String convertTOTitle(int columnNumber){
        StringBuilder sb = new StringBuilder();
        while(columnNumber > 0){
            columnNumber--;
            int c =(columnNumber % 26) + 'a';
            sb.append((char) c);
            columnNumber = columnNumber / 26;
        }
        return sb.reverse().toString().toUpperCase();
        
    }
}
