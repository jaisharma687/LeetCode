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
    int res;
    void dfs(TreeNode* root, int currSum){
        if(root==nullptr) return;
        currSum = currSum*10 + root->val;
        if(root->left==nullptr && root->right==nullptr){
            res += currSum;
        }else{
            dfs(root->left, currSum);
            dfs(root->right, currSum);
        }
    }
    int sumNumbers(TreeNode* root) {
        res = 0;
        dfs(root, 0);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

