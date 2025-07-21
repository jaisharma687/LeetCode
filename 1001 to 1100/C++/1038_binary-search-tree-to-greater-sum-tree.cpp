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
    void solve(TreeNode* root, int& prev){
        if(root==nullptr) return;
        if(root->right) solve(root->right, prev);
        root->val = root->val + prev;
        prev = root->val;
        if(root->left) solve(root->left, prev);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int prev = 0;
        solve(root, prev);
        return root;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

