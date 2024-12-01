package DesignHashMap;

import java.util.ArrayList;
import java.util.Arrays;

public class Solution {
    public static void main(String[] args){


    } 
    private class MyHashMap{
        int size = (int)Math.pow(10,6)+1;
        int[] bucket;
        public MyHashMap(){
            bucket = new int[size];
            Arrays.fill(bucket, -1);
        }
        private void put(int key , int value){
            bucket[key] = value;
        }
        private int get(int key){
            return bucket[key];
        }
        private void remove(int key){
            bucket[key] = -1;
        }
    }
}
