#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Brute force

// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int res = 0;
//         for(int i=0;i<heights.size();i++){
//             int height = heights[i];
//             int left = i;
//             int right = i;
//             while(left>0 && heights[left-1] >= height) left--;
//             while(right<heights.size()-1 && heights[right+1] >= height) right++;
//             res = max(res, height*(right-left+1));
//         }
//         return res;
//     }
// };



// Stack Solution - Optimal

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int mx = 0;
        for(int i=0;i<n;i++){
            if(st.empty()) st.push(i);
            else{
                while(!st.empty() && heights[i]<heights[st.top()]){
                    int height = heights[st.top()];
                    st.pop();
                    int nse = i;
                    int pse = st.empty() ? -1 : st.top();
                    mx = max(mx, height * (nse - pse - 1));
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            mx = max(mx, height * (nse - pse - 1));
        }
        return mx;
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();