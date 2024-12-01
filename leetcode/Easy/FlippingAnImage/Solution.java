package FlippingAnImage;

public class Solution {
    public static void main(String[] args){
        int[][] image = {{1,1,0},{1,0,1},{0,0,0}}; 
        println(flipAndInvertImageBit(image));
    } 
    private static int[][] flipAndInvertImageBit(int[][] image){
        for(int i = 0 ; i < image.length; i++){
            int low = 0; 
            int high = image[i].length-1;
            while(low <= high){
                if(image[i][low] == image[i][high]){
                    image[i][low] ^= 1;
                    image[i][high] = image[i][low];
                }
                low++;
                high--;
            }
        }
        return image;
    }
    private static int[][] flipAndInvertImage(int[][] image){
        for(int i = 0 ; i < image.length; i++){
            int j = image[i].length-1;
            int k = 0;
            while(k <= j){
                if(image[i][k] != image[i][j]){
                    int temp = image[i][k];
                    image[i][k] = image[i][j];
                    image[i][j] = temp;
                } 
                k++;
                j--;
            }
        }
        for(int i = 0 ; i < image.length; i++){
            for(int j = 0 ; j < image[i].length; j++){
                if(image[i][j]== 0){
                    image[i][j] = 1;
                }
                else{
                    image[i][j] = 0;
                }
            }
        }
        return image;
    }
    private static void println(int[][] image){
        for(int i = 0 ; i < image.length; i++){
            System.out.print(i + ": ");
            for(int j = 0 ; j < image[i].length; j++){
                System.out.print(image[i][j]);
            }
            System.out.println();
        }
    }

}