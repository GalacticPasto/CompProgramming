package PathCrossing;

import java.util.HashSet;

public class Solution {
    public static void main(String[] args){
        System.out.println(isPathCrossing("NES"));
    }
    private static boolean isPathCrossing(String path){
        HashSet<String> set = new HashSet<>();
        int x = 0 ; int y = 0;
        set.add("(0,0)");
        for(char c : path.toCharArray()){
             switch(c){
                case 'N' -> y++;
                case 'S' -> y--;
                case 'E' -> x++;
                case 'W' -> x--;
            }
            String ans = "(" + x + "," + y + ")";
            if(set.contains(ans)){
                return true;
            }
            else{
                set.add(ans);
            }
        }
        return false;
    }
}
