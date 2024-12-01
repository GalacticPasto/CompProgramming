package AddBinary;

public class Solution {
       public static void main(String []args){
          System.out.println(getBinary("11", "1"));
          
       }
       private static String getBinary(String a ,String b){
          StringBuilder result = new StringBuilder();
          int carryOver = 0;
          int i = a.length()-1;
          int j = b.length()-1;
          int sum = 0;
          while(i >= 0 || j>= 0){
               sum = carryOver;
               if(i >= 0){
                    sum += a.charAt(i) - '0';
                    System.out.println(a.charAt(i));
               }
               if(j >= 0){
                    sum += b.charAt(j) - '0';
                    System.out.println(b.charAt(j));
               }
               result.append(sum%2);
               carryOver = sum/2;
               i--;
               j--;
          }
          if(carryOver !=0) result.append(carryOver);
          return result.reverse().toString();
       }
}
