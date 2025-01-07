import java.util.*;

class Solution {
    public String minWindow(String s, String t) {
        int n = s.length();
        Map <Character,Integer> tmap = new HashMap<>();
        for(char x: t.toCharArray()) tmap.put(x,tmap.getOrDefault(x,0)+1);
        int count = tmap.size();
        int left=0,right=0,minstart=0,minlen=Integer.MAX_VALUE;
        while(right<n){
            char rightchar = s.charAt(right);
            if(tmap.containsKey(rightchar)){
                tmap.put(rightchar,tmap.get(rightchar)-1);
                if(tmap.get(rightchar)==0) count--;
            }
            while(count==0){
                if(right-left+1<minlen){
                    minlen = right-left+1;
                    minstart = left;
                }
                char leftchar = s.charAt(left);
                if(tmap.containsKey(leftchar)){
                    tmap.put(leftchar,tmap.get(leftchar)+1);
                    if(tmap.get(leftchar)>0) count++;
                }
                left++;
            }
            right++;
        }
        return minlen == Integer.MAX_VALUE ? "" : s.substring(minstart,minstart+minlen);
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
        String s = "ADOBECODEBANC";
        String t = "ABC";
        System.out.println(solution.minWindow(s,t));
    }
}