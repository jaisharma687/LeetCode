import java.util.*;

class Solution {
    boolean checkEven(HashMap<Character,Integer> m){
        for(Map.Entry<Character, Integer> e : m.entrySet()){
            if(e.getValue()%2==1) return false;
        }
        return true;
    }
    public int findTheLongestSubstring(String s) {
        HashMap<Character,Integer> m = new HashMap<>();
        m.put('a',0);
        m.put('e',0);
        m.put('i',0);
        m.put('o',0);
        m.put('u',0);
        for(char key:s.toCharArray()) 
            if(m.containsKey(key)) m.put(key,m.get(key)+1);
        if(checkEven(m)) return s.length();
        HashMap<Character,Integer> p = new HashMap<>(m);
        int window = s.length()-1;
        boolean found = false;
        while(!found){
            m = new HashMap<>(p);
            int n = s.length();
            while(n!=window){
                char key = s.charAt(n-1);
                if(m.containsKey(key)){
                    m.put(key,m.get(key)-1);
                }
                n--;
            }
            for(int i=0;i+window<=s.length();i++){
                if(i>0){
                    char keyOut = s.charAt(i-1);
                    char keyIn = s.charAt(i+window-1);
                    if(m.containsKey(keyOut)){
                        m.put(keyOut,m.get(keyOut)-1);
                    }
                    if(m.containsKey(keyIn)){
                        m.put(keyIn,m.get(keyIn)+1);
                    }
                }
                if(checkEven(m)){
                    found = true;
                    break;
                }
            }
            if(found) break;
            window--;
        } 
        return window;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}