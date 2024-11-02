import java.util.*;

class Solution {
    public boolean isCircularSentence(String sentence) {
        String[] words = sentence.split(" ");
        int n = words.length;
        for(int i=0;i<n-1;i++){
            int len = words[i].length();
            if(words[i].charAt(len-1)!=words[i+1].charAt(0)){
                return false;
            }
        }
        int len = words[n-1].length();
        if(words[n-1].charAt(len-1)!=words[0].charAt(0)){
            return false;
        }
        return true;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}