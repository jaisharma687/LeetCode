import java.util.*;

class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        for(int[] x: res) Arrays.fill(x,0);
        int i = 1;
        int r_min = 0;
        int c_min = 0;
        int r_max = n-1;
        int c_max = n-1;
        while(i != n*n + 1){
            for(int j=c_min;j<=c_max && i != n*n + 1;j++){
                res[r_min][j] = i;
                i++;
            }
            r_min++;
            for(int j=r_min;j<=r_max && i != n*n + 1;j++){
                res[j][c_max] = i;
                i++;
            }
            c_max--;
            for(int j=c_max;j>=c_min && i != n*n + 1;j--){
                res[r_max][j] = i;
                i++;
            }
            r_max--;
            for(int j=r_max;j>=r_min && i != n*n + 1;j--){
                res[j][c_min] = i;
                i++;
            }
            c_min++;
        }
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}