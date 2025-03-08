#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
    public:
        // Solution 1: Using HashMap, TC=O(n*n), SC = O(n)
        // vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        //     int n = grid.size();
        //     unordered_set<int> st;
        //     int rep;
        //     bool found = false;
        //     for(auto& x: grid){
        //         for(int y: x){
        //             if(!found && st.find(y)!=st.end()){
        //                 rep = y;
        //             }
        //             st.insert(y);
        //         }
        //     }
        //     for(int i=1;i<=n*n;i++){
        //         if(st.find(i)==st.end()){
        //             return {rep,i};
        //         }
        //     }
        //     return {rep,-1};
        // }
    
        // Solution 2: Using Maths, TC=O(n*n), SC=O(1)
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            int x; // repeated
            int y; // missing
            long long diff = 0;
            long long diffsqr = 0;
            for(int i=1;i<=n*n;i++){
                diff += i;
                diffsqr += i*i;
            }
            cout<< diff<<" "<<diffsqr<<endl;
            for(auto& p: grid){
                for(int q: p){
                    diff -= q;
                    diffsqr -= q*q;
                }
            }
            cout<< diff<<" "<<diffsqr<<endl;
            long long sum = diffsqr/diff;
            y = (sum+diff)/2;
            x = sum - y;
            return {x,y};
        }
    };

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();