package FindIfPathsExistsInGraph;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Solution {
    private static boolean destinationReached = false;
    public static void main(String[] args){

    } 
    private static boolean validPath(int n , int[][] edges, int source , int destination){
        HashMap<Integer,List<Integer>> map = new HashMap<>();
        for(int i = 0 ; i < n ; i++) map.put(i, new ArrayList<>());
        for(int[] pairs: edges){
            map.get(pairs[0]).add(pairs[1]);
            map.get(pairs[1]).add(pairs[0]);
        }  
        boolean[] hasVisited = new boolean[n]; 
        dfs(map, hasVisited, source, destination);
        return destinationReached;
    }
    private static void dfs(HashMap<Integer, List<Integer>> map,boolean[] hasVisited,  int source, int destination) {
        if(hasVisited[source] || destinationReached){
            return;
        }
        hasVisited[source] = true;

        for(int neigh : map.get(source)){
            if(neigh == destination){
                destinationReached = true;
                break;
            }
            if(!hasVisited[neigh]){
                dfs(map, hasVisited, source, destination);
            }
        }
    }
}
