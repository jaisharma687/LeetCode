import java.util.*;

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        int row = 0;
        while(row<m && matrix[row][n-1]<target) row++;
        if(row==m) return false;
        int l =0;
        int r = n-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(matrix[row][mid]<target) l= mid+1;
            else if(matrix[row][mid] > target) r = mid-1;
            else return true;
        }
        return false;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}