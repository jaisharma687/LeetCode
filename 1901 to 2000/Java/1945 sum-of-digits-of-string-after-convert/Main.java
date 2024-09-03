import java.util.*;

class Solution {
    public String toString(int n){
        String res = "";
        while(n>0){
            char t = (char)(n%10 + '0');
            res = t + res;
            n/=10;
        }
        return res;
    }
    public int operation(String s){
        int sum = 0;
        for(char x: s.toCharArray()){
            sum += (int)(x-'0');
        }
        return sum;
    }
    public int getLucky(String s, int k) {
        int sum = 0;
        for(char x: s.toCharArray()){
            int t = (int)(x-'a') + 1;
            sum += t%10 + t/10;
        }
        if(k==1) return sum;
        String res = toString(sum);
        k--;
        while(k>0){
            int r = operation(res);
            if(k==1) return r;
            res = toString(r);
            k--;
        }
        return -1;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}
