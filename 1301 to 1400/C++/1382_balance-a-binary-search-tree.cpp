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
    vector<int> inorder;
    void dfs(TreeNode* root){
        if(root==nullptr) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* buildTree(int l, int r){
        if(l>r) return nullptr;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = buildTree(l, mid-1);
        root->right = buildTree(mid+1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        int l = 0;
        int r = inorder.size()-1;
        return buildTree(l, r);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

