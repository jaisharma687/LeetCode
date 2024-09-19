import java.util.*;

class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int mx = 0;
        int n = heights.length;
        for(int i=0;i<n;i++){
            if(!st.isEmpty()){
                while(!st.isEmpty() && heights[i]<heights[st.peek()]){
                    int height = heights[st.peek()];
                    st.pop();
                    int nse = i;
                    int pse = st.isEmpty() ? -1 : st.peek();
                    mx = Math.max(mx, height * (nse - pse - 1));
                }
            }    
            st.push(i);
        }
        while(!st.isEmpty()){
            int height = heights[st.peek()];
            st.pop();
            int nse = n;
            int pse = st.isEmpty() ? -1 : st.peek();
            mx = Math.max(mx, height * (nse - pse - 1));
        }
        return mx;
    }
}

public class Main{
    public static void main(String[] args) {
        Solution solution = new Solution();
    }
}