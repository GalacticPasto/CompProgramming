package FindTheTownJudge;
public class Solution {
    public static void main(String[] args){
        int[][] judge = {{1,3},{2,3}};
        System.out.println(findTheTownJudge(3, judge));
    }
    public static int findTheTownJudge(int n , int[][] trust){
        int[] ppl = new int[n+1];
        int[] trusted= new int[n+1];
        for(int i = 0 ; i < trust.length ; i++){
                ppl[trust[i][0]] += 1; 
                trusted[trust[i][1]] +=1; 
        }
        for(int i = 1 ; i < trusted.length ; i++){
            if(ppl[i] == 0 && trusted[i] == n-1){
                return i;
            }
        }
        return -1;
    } 
}
