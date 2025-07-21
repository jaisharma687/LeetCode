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
//     unordered_map<TreeNode*, TreeNode*> parent;
//     void inorder(TreeNode* root, int start, TreeNode*& st){
//         if(root==nullptr) return;
//         inorder(root->left, start, st);
//         if(root->left !=nullptr) parent[root->left]  = root;
//         if(root->right!=nullptr) parent[root->right] = root;
//         if(root->val==start) st = root;
//         inorder(root->right, start, st);
//     }
//     int amountOfTime(TreeNode* root, int start) {
//         parent.clear();
//         TreeNode* st;
//         inorder(root, start, st);
//         queue<TreeNode*> q;
//         q.push(st);
//         int time = -1;
//         unordered_set<int> visited;
//         while(!q.empty()){
//             int size = q.size();
//             while(size--){
//                 auto node = q.front();
//                 q.pop();
//                 visited.insert(node->val);
//                 if(node->left && visited.find(node->left->val)==visited.end()) 
//                     q.push(node->left);
//                 if(node->right && visited.find(node->right->val)==visited.end()) 
//                     q.push(node->right);
//                 if(parent.find(node)!=parent.end() && visited.find(parent[node]->val)==visited.end()) 
//                     q.push(parent[node]);
//             }
//             time++;
//         }
//         return time;
//     }
// };

class Solution {
public:
    int res = INT_MIN;
    int dfs(TreeNode* root, int& start){
        if(root==nullptr) return 0;
        int lh = dfs(root->left, start);
        int rh = dfs(root->right, start);
        if(root->val==start){
            res = max(lh, rh);
            return -1;
        }else if(lh>=0 && rh>=0){
            return 1 + max(lh, rh);
        }else{
            int d = abs(lh) + abs(rh);
            res = max(res, d);
            return min(lh,rh)-1;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

