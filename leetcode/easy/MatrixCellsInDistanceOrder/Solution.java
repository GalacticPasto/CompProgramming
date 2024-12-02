package MatrixCellsInDistanceOrder;

import java.util.ArrayList;
import java.util.HashMap;

public class Solution{

    public static void main(String[]args){
        allCellsDistOrder(0, 0, 0, 0);
    }
    private static int[][] allCellsDistOrder(int rows, int cols, int rCenter,int cCenter){
        HashMap<Integer,ArrayList<int[]>> ans = new HashMap<>();
        for(int i = 0 ; i < rows; i++){
            for(int j = 0 ; j < cols ; j++){
                int distance = Math.abs(rCenter - i) + Math.abs(cCenter - j);
                if(ans.containsKey(distance)){
                    int[] arr = {i,j};
                    ans.get(distance).add(distance, arr);
                }
                else{
                    ArrayList<int[]> list = new ArrayList<>();
                    list.add(new int[]{i,j});
                    ans.put(distance,list);
                }
            }
        }
        int ind = 0;
        int[][] result = new int[ans.size()][2];
        for(int i : ans.keySet()){
            ArrayList<int[]> list = ans.get(i);
            
            for(int[] row : list){
               result[ind++] = row;
            }
        }
        return result;
    }
}