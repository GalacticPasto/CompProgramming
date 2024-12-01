package FirstBadVersion;

public class Solution {
    public static void main(String []args){
        Version ve = new Version(0);
        Version v1 = new Version(1);
        Version v2 = new Version(2);
        Version v3 = new Version(3);
        Version v4 = new Version(4);
        Version v5 = new Version(5);
        v4.isBadVersion = true;
        v5.isBadVersion = true;

    } 
    private static int firstBadVersion(int n){
        Version ve = new Version(0);
        if(ve.isBadVersion(n) == false) return -1;
        int low = 0;
        int high = n-1;
        int mid = low + (high-low)/2;
        while(low <= high){
            if (ve.isBadVersion(mid) == false) {
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    private static class Version{
        private boolean isBadVersion;
        private int version;
        public Version(int n){
            this.version = n; 
            this.isBadVersion = false;
        }
        public boolean isBadVersion(int version){
            return isBadVersion;
        }
    }
}
