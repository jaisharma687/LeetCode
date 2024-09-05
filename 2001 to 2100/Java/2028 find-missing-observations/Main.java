import java.util.*;

class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;
        int sm = 0;
        for(int x : rolls) sm += x;
        int sn = mean * (n+m) - sm;
        if(sn > 6*n || sn < n) return new int[0];
        int[] res = new int[n];
        for(int i=0;i<n;i++) res[i] = 1;
        int cur = n;
        int i = 0;
        while(sn-cur+1>6){
            res[i] = 6;
            i++;
            cur += 5;
        }
        res[i] = sn - cur + 1;
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}
