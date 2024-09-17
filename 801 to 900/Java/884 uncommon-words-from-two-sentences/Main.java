import java.util.*;

class Solution {
    public HashMap<String,Integer> m = new HashMap<>();
    void tokenize(String s){
        int left = 0;
        int right = 0;
        for(int i=0;i<s.length();i++){
            char x = s.charAt(i);
            if(x==' '){
                String sub = s.substring(left,right);
                if(m.containsKey(sub)){
                    int val = m.get(sub);
                    m.put(sub,val+1);
                }
                else m.put(sub,1);
                left = i+1;
                right = i+1;
            }else right++;
        }
        String sub = s.substring(left,right);
        if(m.containsKey(sub)){
            int val = m.get(sub);
            m.put(sub,val+1);
        }
        else m.put(sub,1);
    }
    public String[] uncommonFromSentences(String s1, String s2) {
        tokenize(s1);
        tokenize(s2);
        int count = 0;
        for(Map.Entry<String,Integer> e : m.entrySet()){
            if(e.getValue()==1) count++;
        }
        String[] res = new String[count];
        for(Map.Entry<String,Integer> e : m.entrySet()){
            if(e.getValue()==1) res[--count] = e.getKey();
        }
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}