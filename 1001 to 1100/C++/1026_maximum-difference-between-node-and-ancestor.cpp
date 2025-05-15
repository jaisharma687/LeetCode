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
    void dfs(TreeNode* root, pair<int,int> maxMin, int& diff){
        if(root==nullptr) return;
        int val = root->val;
        maxMin.first = max(maxMin.first, val);
        maxMin.second = min(maxMin.second, val);
        diff = max(diff ,maxMin.first - maxMin.second);
        dfs(root->left, maxMin, diff);
        dfs(root->right, maxMin, diff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;
        pair<int, int> pair = {INT_MIN, INT_MAX};
        dfs(root, pair, diff);
        return diff;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

