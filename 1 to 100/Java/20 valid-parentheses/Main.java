import java.util.*;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for(char x : s.toCharArray()){
            if(x=='(' || x=='{' || x=='[') stack.push(x);
            else{
                if(stack.empty()) return false;
                if((x == ')' && stack.peek() == '(')
                || (x == '}' && stack.peek() == '{')
                || (x == ']' && stack.peek() == '[')){
                    stack.pop();
                }
                else return false;
            }
        }   
        return stack.empty();
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}
