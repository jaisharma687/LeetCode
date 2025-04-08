import java.util.*;

class Solution {
    public String longestPrefix(String s) {
        for (int i = s.length() - 1; i > 0; i--) {
            String sub = s.substring(0, i);
            if (s.endsWith(sub)) {
                return sub;
            }
        }
        return "";
    }
}


public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}