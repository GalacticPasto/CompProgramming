package GenerateParentheses;
import java.util.ArrayList;
import java.util.List;

@SuppressWarnings("unchecked")

public class Solution {
    public static void main(String[] args){
        printList(generateParentheses(1));
    }
    private static List<String> generateParentheses(int n){
        ArrayList<String>[] table = new ArrayList[n+1];
        ArrayList<String> parentheses = new ArrayList<>();

        parentheses.add("()");
        table[0] = parentheses;
        ArrayList<String> parentheses1 = new ArrayList<>();
        parentheses1.add("()()");
        parentheses1.add("(())");
        table[1] = parentheses1; 

        for(int i = 2 ; i < n ; i++){
            ArrayList<String> previous = table[i-1];
            ArrayList<String> newParentheses = new ArrayList<String>();
            for(String st : previous){
                int counter = 0;
                String ans = "";
                for (int k = 0; k < st.length(); k++) {
                    for (int j = 0; j < st.length(); j++) {
                        if (j == counter) {
                            ans += "()";
                        }
                        ans += st.charAt(j);
                    }
                    counter++;
                    if(!newParentheses.contains(ans)){
                        newParentheses.add(ans);
                    }
                    ans ="";
                }
            }
            table[i] = newParentheses;
        }
        return table[n-1];
    }
    private static void printList(List<String> list){
        for(String x : list){
            System.out.println(x);
        }
    }
}
