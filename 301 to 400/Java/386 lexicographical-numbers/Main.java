import java.util.*;

class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        int val = 1;
        while(res.size() != n){
            res.add(val);
            if(val * 10 <= n){
                val *= 10;
            }
            else{
                while(val == n || val % 10 == 9) val = val / 10;
                val++;
            }
        }
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}