import java.util.*;

class Solution {
    public int strToNum(String s){
        int n = 0;
        if(s.charAt(0)!='-'){
            for(char x: s.toCharArray()){
                n = n*10 + (int)(x-'0');
            }
        }
        else{
            for(int i=1;i<s.length();i++){
                n = n*10 + (int)(s.charAt(i)-'0');
            }
            n = -n;
        }
        return n;
    }
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for(String x:tokens){
            if(!x.equals("+") && !x.equals("-") && !x.equals("*") && !x.equals("/")){
                int n = strToNum(x);
                st.push(n);
            }
            else{
                int a = st.peek();
                st.pop();
                int b = st.peek();
                st.pop();
                if(x.equals("+")) st.push(b+a);
                if(x.equals("-")) st.push(b-a);
                if(x.equals("*")) st.push(b*a);
                if(x.equals("/")) st.push(b/a);
            }
        }
        return st.peek();
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}