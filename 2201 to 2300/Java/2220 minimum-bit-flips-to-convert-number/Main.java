import java.util.*;

class Solution {
    String toBinary(int n){
        String res = "";
        while(n>0){
            char t = (char)(n%2 + '0');
            res = t + res;
            n/=2;
        }
        return res;
    }
    public int minBitFlips(int start, int goal) {
        String st = toBinary(start);
        String gl = toBinary(goal);
        while(gl.length()<st.length()){
            gl = "0" + gl;
        }
        while(gl.length()>st.length()){
            st = "0" + st;
        }
        int n = st.length();
        int flips = 0;
        for(int i=0;i<n;i++){
            if(st.charAt(i) != gl.charAt(i)) flips++;
        }
        return flips;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}