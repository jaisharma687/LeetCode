import java.util.*;

class Solution {
    boolean validate(int[] pos, int n){
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int x = j - i;
                int y = pos[j] - pos[i];
                if(x == Math.abs(y)) return false;
            }
        }
        return true;
    }
    void solve(List<List<String>> res, List<String> solution, int[] pos, boolean[] visited, String solString, int n){
        if(solution.size() == n){
            if(validate(pos, n)){
                res.add(new ArrayList<>(solution));
            }
            return;
        }
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                visited[i] = true;
                String sol = solString.substring(0, i) + 'Q' + solString.substring(i + 1);
                solution.add(sol);
                pos[solution.size() - 1] = i;
                solve(res, solution, pos, visited, solString, n);
                visited[i] = false;
                solution.remove(solution.size() - 1);
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> res = new ArrayList<>();
        List<String> solution = new ArrayList<>();
        int[] pos = new int[n];
        boolean[] visited = new boolean[n];
        String solString = ".".repeat(n);
        solve(res, solution, pos, visited, solString, n);
        return res;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}