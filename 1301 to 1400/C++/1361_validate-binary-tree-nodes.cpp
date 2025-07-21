#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int, int> mpp;
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<n;i++){
            int lc = leftChild[i];
            int rc = rightChild[i];
            if(lc!=-1){
                if(mpp.find(lc)!=mpp.end()) return false;
                mpp[lc] = i;

                adj[i].push_back(lc);
            }
            if(rc!=-1){
                if(mpp.find(rc)!=mpp.end()) return false;
                mpp[rc] = i;

                adj[i].push_back(rc);
            }
        }
        int root = -1;
        for(int i=0;i<n;i++){
            if(mpp.find(i)==mpp.end()){
                if(root!=-1) return false;
                root = i;
            }
        }
        if(root==-1) return false;
        unordered_set<int> visited;
        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int node = q.front();
            visited.insert(node);
            q.pop();
            vector<int> adjNodes = adj[node];
            int l = adjNodes.size();
            if(l>2) return false;
            for(int i=0;i<l;i++){
                int adjNode = adjNodes[i];
                if(visited.find(adjNode)!=visited.end()) return false;
                visited.insert(adjNode);
                q.push(adjNode);
            }
        }
        return visited.size()==n;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

