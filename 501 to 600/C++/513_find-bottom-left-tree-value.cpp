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
    int leftMost;
    int maxLevel = -1;
    void dfs(TreeNode* root, int l){
        if(root==nullptr) return;
        dfs(root->left, l+1);
        dfs(root->right, l+1);
        if(l > maxLevel){
            maxLevel = l;
            leftMost = root->val;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==nullptr) return -1;
        dfs(root, 0);
        return leftMost;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

