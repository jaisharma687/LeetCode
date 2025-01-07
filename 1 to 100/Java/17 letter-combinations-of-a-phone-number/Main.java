import java.util.*;

class Solution {
    HashMap<Character,String> keyboard = new HashMap<>();
    void solve(List<String> res, String temp, String d, int idx){
        if(idx == d.length()){
            res.add(temp);
            return;
        }
        String t = keyboard.get(d.charAt(idx));
        int n = t.length();
        for(int i=0;i<n;i++){
            solve(res,temp+t.charAt(i),d,idx+1);
        }
        return;
    }
    public List<String> letterCombinations(String digits) {
        if(digits.equals("")) return new ArrayList<>(0);
        keyboard.put('2',"abc");
        keyboard.put('3',"def");
        keyboard.put('4',"ghi");
        keyboard.put('5',"jkl");
        keyboard.put('6',"mno");
        keyboard.put('7',"pqrs");
        keyboard.put('8',"tuv");
        keyboard.put('9',"wxyz");
        List<String> res = new ArrayList<>();
        solve(res,"",digits,0);
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}