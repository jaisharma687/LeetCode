import java.util.*;

class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        Set<Character> letters = new HashSet<>();
        for(char x: allowed.toCharArray()) letters.add(x);
        int count = 0;
        for(String word:words){
            boolean consistent = true;
            for(char w:word.toCharArray()){
                if(!letters.contains(w)){
                    consistent = false;
                    break;
                }
            }
            if(consistent) count++;
        }
        return count;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}