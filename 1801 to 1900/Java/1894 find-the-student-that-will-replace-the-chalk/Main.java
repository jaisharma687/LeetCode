import java.util.*;

class Solution {
    public int chalkReplacer(int[] chalk, int k) {
        long s = 0;
        for(int x: chalk) s+= x;
        long rem = k%s;
        int n = chalk.length;
        for(int i=0;i<n;i++){
            rem -= chalk[i];
            if(rem<0) return i;
        }
        return -1;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}