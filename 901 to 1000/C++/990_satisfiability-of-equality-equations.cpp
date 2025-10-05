#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x], parent);
    }

    void unionFunc(int x, int y, vector<int>& parent, vector<int>& rank){
        int xParent = find(x, parent);
        int yParent = find(y, parent);
        if(xParent==yParent) return;
        if(rank[xParent]>rank[yParent]){
            parent[yParent] = xParent;
        }else if(rank[xParent]<rank[yParent]){
            parent[xParent] = yParent;
        }else{
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        vector<int> rank(26,0);
        for(int i=0;i<26;i++) parent[i] = i;
        for(string equation: equations){
            string op = equation.substr(1,2);
            if(op=="=="){
                int x = equation[0]-'a';
                int y = equation[3]-'a';
                unionFunc(x,y,parent,rank);
            }
        }

        for(string equation: equations){
            string op = equation.substr(1,2);
            if(op=="!="){
                int x = equation[0]-'a';
                int y = equation[3]-'a';
                int xParent = find(x, parent);
                int yParent = find(y, parent);
                if(xParent == yParent) return false;
            }
        }
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}