package DetermineColorOfACessboardSquare;

public class Solution {
    public static void main(String[] args){
        System.out.println((int)'1');
        System.out.println(squareIsWhite("a1"));
    } 
    private static boolean squareIsWhite(String coordinates){
        int x= (int)coordinates.charAt(0)-'a'+1; 
        int y = (int)coordinates.charAt(1)-49+1;
        System.out.println(x + " " + y);
        if((x & 1) == 1){
            if ((y & 1) == 1){
                return true;
            }
        }
        else{
            if ((y & 1) == 0){
                return true;
            }
        }
        return false;
    }

}
