package ReplaceAllQuestionsToAvoidConsecutiveRepatingCharacters;

public class Solution{
    public static void main(String[] args){
        System.out.println(modifyString(""));
    }
    private static String modifyString(String s){
        StringBuilder sb = new StringBuilder();
        for(int i = 0 ; i < s.length(); i++){
            if(s.charAt(i) == '?'){
                for(int aph= 'a'; aph <= 'z' ; aph++){
                    if(i > 0 && s.charAt(i-1) == aph) continue;
                    if(i < s.length()-1 && s.charAt(i+1) == aph) continue;
                    sb.append(aph);
                    break;
                }
            }
            else{
                sb.append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}
