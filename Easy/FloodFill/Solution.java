package FloodFill;

public class Solution {
    public static void main(String[] args){
        int[][] matirx = {{1,1,1},{1,1,0},{0,0,1}};
        printArray(matirx);
        printArray(floodFill(matirx, 1,1,2));
    } 
    private static int[][] floodFill(int[][] image ,int sr, int sc , int newColor){
        fill(image, sr, sc, image[sr][sc],newColor);
        return image;
    }

    private static void fill(int[][] image,int sr, int sc,int color, int newColor){
        if(sr < 0 || sc < 0 || sr >= image.length || sc >= image[0].length || image[sr][sc] != color){
            return;
        }
        image[sr][sc] = newColor;
        fill(image, sr-1, sc, color,newColor);
        fill(image, sr+1, sc, color,newColor);
        fill(image, sr, sc-1, color,newColor);
        fill(image, sr, sc+1, color,newColor);
    } 
    private static void printArray(int[][] matrix){
        for(int i = 0 ; i < matrix.length ; i++){
            System.out.print(i + ":");
            for(int j = 0 ; j < matrix[i].length ;j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }
}
