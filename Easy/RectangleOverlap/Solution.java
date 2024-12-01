package RectangleOverlap;

public class Solution {
    public static void main(String[] args){

    } 
    //  0   1  2  3 
    // {5, 15 ,8,18 }
    //  x1 y1 x2 y2
    //  0  1   2  3 
    // {0, 3 , 7 ,9}
    //  x1 y1 x2 y2
    private static boolean isRectangleOverlap(int[] rec1, int[] rec2){
        if(rec1[2] > rec2[0] && rec1[3] > rec2[1] && rec1[0] < rec2[2] && rec1[1] < rec2[3]){
            return true;
        }

        return false;
    }
}
