import java.util.*;

class Solution {
    public List<Integer> backtrack(int left, int right, String exp){
        List<Integer> res = new ArrayList<>();
        for(int i=left;i<=right;i++){
            if(exp.charAt(i)=='+' || exp.charAt(i)=='-' || exp.charAt(i)=='*'){
                List<Integer> num1 = backtrack(left,i-1,exp);
                List<Integer> num2 = backtrack(i+1,right,exp);
                for(int x:num1){
                    for(int y:num2){
                        if(exp.charAt(i)=='+') res.add(x+y);
                        else if(exp.charAt(i)=='-') res.add(x-y);
                        else if(exp.charAt(i)=='*') res.add(x*y);
                    }
                }
            }
        }
        if(res.size()==0){
            res.add(Integer.parseInt(exp.substring(left,right+1)));
        }
        return res;
    }
    public List<Integer> diffWaysToCompute(String expression) {
        return backtrack(0,expression.length()-1,expression);
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}