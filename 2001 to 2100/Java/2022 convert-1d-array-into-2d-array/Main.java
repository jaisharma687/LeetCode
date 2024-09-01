import java.util.*;

class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        int k = original.length;
        if(k!=m*n) return new int[0][0];
        int i=0;
        int[][] grid = new int[m][n];
        for(int r=0;r<m;r++)
            for(int c=0;c<n;c++)
                grid[r][c] = original[i++];
        return grid;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}