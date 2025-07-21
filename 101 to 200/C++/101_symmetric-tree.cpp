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
    bool dfs(TreeNode* r1, TreeNode* r2){
        if(r1==nullptr && r2==nullptr) return true;
        if(r1==nullptr || r2==nullptr) return false;
        return r1->val==r2->val && dfs(r1->left,r2->right) && dfs(r1->right,r2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        return dfs(root->left, root->right);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

