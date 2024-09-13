import java.util.*;

class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length;
        for(int i=1;i<n;i++){
            arr[i] = arr[i-1]^arr[i];
        }
        int[] res = new int[queries.length];
        for(int i=0;i<queries.length;i++){
            int l =queries[i][0];
            int r =queries[i][1];
            if(l==0) res[i] = arr[r];
            else res[i] = arr[r] ^ arr[l-1];
        }
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}