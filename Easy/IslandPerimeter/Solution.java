package IslandPerimeter;
import java.util.List;

public class Solution {
   public static void main(String []args){
    List<List<Integer>> list = List.of(List.of(0,1,0,0),List.of(1,1,1,0),List.of(0,1,0,0), List.of(1,1,0,0)); 
    printGrid(insertIsland(list));
    System.out.println();
    System.out.println((islandPerimeter(insertIsland(list))));
   }

   public static int islandPerimeter(int[][] grid) {
       int perimeter = 0;
       for (int i = 0; i < grid.length; i++) {
           for (int j = 0; j < grid[i].length; j++) {
               if (grid[i][j] == 1) {
                   perimeter += 4;
                   if (i > 0 && grid[i - 1][j] == 1) {
                       perimeter -= 2;
                   }
                   if (j > 0 && grid[i][j - 1] == 1) {
                       perimeter -= 2;
                   }
               }
           }
       }
       return perimeter;
   }
   private static void printGrid(int[][] grid){
        for(int i = 0 ; i < grid.length; i++){
            System.out.print(i + ": ");
            for(int j = 0 ; j < grid[i].length; j++ ){
                System.out.print(grid[i][j] + " ");
            }
        System.out.println();
        }
   }

   private static int[][] insertIsland(List<List<Integer>> islands) {
       int[][] grid = new int[islands.size()][islands.size()];
       for (int i = 0; i < islands.size(); i++) {
           List<Integer> row = islands.get(i);
           for (int j = 0; j < grid[i].length; j++) {
               grid[i][j] = row.get(j);
           }
       }
       return grid;
   }
}
