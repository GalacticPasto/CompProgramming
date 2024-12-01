package FirstUniqChar;


public class Solution {
    public static void main(String[] main) {
        System.out.println(firstUniqChar("loveleetcode"));
    }

    private static int firstUniqChar(String s) {
     char[]cha = s.toLowerCase().toCharArray();
     int[] state = new int[26];
        
        for(int i = 0 ; i <cha.length ;i++){
            int index = cha[i] -'a';
             state[index]+= 1;
        }
        for(int i = 0 ; i <cha.length ;i++){
            int index = cha[i] -'a';
            if(state[index] <= 1){
                return i;
            }
        }
     return -1;
    }
}
