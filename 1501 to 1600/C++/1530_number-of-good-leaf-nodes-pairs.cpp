#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     unordered_map<TreeNode*, vector<TreeNode*>> adj;
//     unordered_set<TreeNode*> leaves;
//     void dfs(TreeNode* root){
//         if(root==nullptr) return;
//         if(root->left){
//             adj[root->left].push_back(root);
//             adj[root].push_back(root->left);
//         }
//         if(root->right){
//             adj[root->right].push_back(root);
//             adj[root].push_back(root->right);
//         }
//         if(root->left==nullptr && root->right==nullptr){
//             leaves.insert(root);
//         }
//         dfs(root->left);
//         dfs(root->right);
//     }
//     int bfs(TreeNode* src, int d){
//         queue<TreeNode*> q;
//         q.push(src);
//         int currD = 0;
//         int count = 0;
//         unordered_set<TreeNode*> visited;
//         while(!q.empty() && currD < d){
//             int size = q.size();
//             while(size--){
//                 auto node = q.front();
//                 q.pop();
//                 visited.insert(node);
//                 for(auto& neigh: adj[node]){
//                     if(visited.find(neigh)==visited.end()){
//                         q.push(neigh);
//                         if(leaves.find(neigh)!=leaves.end()){
//                             count++;
//                         }
//                     }
//                 }
//             }
//             currD++;
//         }
//         return count;
//     }
//     int countPairs(TreeNode* root, int distance) {
//         adj.clear();
//         dfs(root);
//         int cnt = 0;
//         for(auto leaf: leaves){
//             cnt += bfs(leaf, distance);
//         }
//         return cnt/2;
//     }
// };

class Solution {
public:
    int cnt = 0;
    vector<int> dfs(TreeNode* root, int d){
        if(root==nullptr) return {};
        auto left = dfs(root->left,d);
        auto right = dfs(root->right,d);
        if(root->left==nullptr && root->right==nullptr){
            return {1};
        } 
        vector<int> res;
        for(int l: left){
            for(int r: right){
                if(l!=0 && r!=0 && l+r<=d) cnt++;
            }
        }
        for(int l: left){
            if(l!=0 && l+1<d) res.push_back(l+1);
        }
        for(int r: right){
            if(r!=0 && r+1<d) res.push_back(r+1);
        }
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return cnt;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

