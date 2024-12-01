import java.util.*;

class Solution {
    public String rotateLeft(String s){
        String first = s.substring(0,1);
        s=s.substring(1);
        s += first;
        return s;
    }
    public boolean rotateString(String s, String goal) {
        int n = s.length();
        if(n!=goal.length()){
            return false;
        }
        String initial = goal;
        int i=0;
        while(i<n){
            if(goal.equals(s)){
                return true;
            }
            goal = rotateLeft(goal);
            if(goal.equals(initial)){
                break;
            }
            i++;
        }
        return false;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}