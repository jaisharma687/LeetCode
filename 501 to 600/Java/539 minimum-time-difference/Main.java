import java.util.*;

class Solution {
    public int toTime(String s){
        String h = s.substring(0,2);
        String m = s.substring(3,5);
        int time = 0;
        for(char x: h.toCharArray()){
            time = time*10 + (int)(x-'0');
        }
        for(char x: m.toCharArray()){
            time = time*10 + (int)(x-'0');
        }
        return time;
    }
    public int calculateTimeDiff(int a, int b){
        int hr = Math.abs(a/100-b/100);
        int min = a%100 - b%100;
        if(hr == 0) return Math.abs(min);
        if(hr>12){
            hr = 24-hr;
            return hr*60 + min;
        }
        return hr*60 - min;
    }
    public int findMinDifference(List<String> timePoints) {
        int[] time = new int[timePoints.size()];
        for(int i=0;i<timePoints.size();i++){
            time[i] = toTime(timePoints.get(i));
        }
        Arrays.sort(time);
        int d = calculateTimeDiff(time[0],time[timePoints.size()-1]);
        for(int i=0;i<timePoints.size()-1;i++){
            d = Math.min(d,calculateTimeDiff(time[i],time[i+1]));
            if(d==0) return d;
        }
        return d;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}