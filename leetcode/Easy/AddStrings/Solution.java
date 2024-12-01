package AddStrings;

public class Solution {
    public static void main(String[] args){
        System.out.println(addStrings("456","77"));
    } 
    private static String addStrings(String num1, String num2) {
        int i = num1.length()-1;
        int j = num2.length() -1;
        int carryOver = 0; 
        StringBuilder sb = new StringBuilder();
        while(i >= 0 || j >= 0){
            int n1 = (i < 0) ? 0 : num1.charAt(i) - '0'; 
            int n2 = (j < 0) ? 0 : num2.charAt(j) - '0'; 
            
            int sum = n1 + n2 + carryOver;
            sb.append(sum % 10);
            carryOver = sum /10;
            
            i--;
            j--;
        }
        if(carryOver == 1){
            sb.append(carryOver);
        }
        return sb.reverse().toString();
    }
    
}
