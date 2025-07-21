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

class Solution {
public:
    int moves = 0;
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        moves += abs(l) + abs(r);
        return l + r + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

