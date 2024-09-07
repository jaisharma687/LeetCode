import java.util.*;

class Solution {
    public void recursion(String s, List<String>res, int n, int m){
        if(n==0 && m==0){
            res.add(s);
            return;
        }
        if(n>0) recursion(s+"(",res,n-1,m);
        if(m>n) recursion(s+")",res,n,m-1);
        return;
    }
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        recursion("",res,n,n);
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}