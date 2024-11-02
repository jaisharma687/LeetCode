import java.util.*;

class Solution {
    public String makeFancyString(String s) {
        StringBuilder out = new StringBuilder();
        int m = 1;
        char prev = ' ';
        char[] sarr = s.toCharArray();
        for(char x: sarr){
            if(prev != x){
                out.append(x);
                m = 1;
            }
            else{
                if(m<2){
                    out.append(x);
                }
                m++;
            }
            prev = x;
        }
        return out.toString();
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}