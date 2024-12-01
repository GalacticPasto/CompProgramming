package MaximumPopulationYear;

import java.util.HashMap;

public class Solution {
    public static  void main(String[] args){
        int[][] logs={{1950,1961},{1960,1971},{1970,1981}}; 
        System.out.println(maximumPopulation(logs));
    } 
    private static int maximumPopulation(int[][] logs){
        int[] pop = new int[2050];
        for(int[] row : logs){
            pop[row[0]]++;
            pop[row[1]]--;
        }
        int max = 0;
        int maxYear = 0;
        for(int i = 1950 ; i < 2050 ; i++){
            pop[i] += pop[i-1];
            if(pop[i] > max){
                max = Math.max(pop[i], max);
                maxYear = i;
            }
        }
        return maxYear;
    }
}
