import java.util.*;
import javafx.util.Pair;

class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        List<Pair<Integer,Integer>> ps = new ArrayList<>();
        for(int i=0;i<speed.length;i++){
            ps.add(new Pair<Integer,Integer>(position[i],speed[i]));
        }
        ps.sort((p1, p2) -> Integer.compare(p2.getKey(), p1.getKey()));
        Stack<Pair<Integer, Integer>> st = new Stack<>();
        for(Pair<Integer,Integer> x: ps){
            if(st.isEmpty()) st.push(x);
            else{
                Pair<Integer,Integer> p2 = st.peek();
                double t1 = (double)(target-x.getKey())/x.getValue();
                double t2 = (double)(target-p2.getKey())/p2.getValue();
                if(t1 > t2) st.push(x);
            }
        }
        return st.size();
    }
}
public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}