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
    typedef pair<int,int> P;
    P dfs(TreeNode* root,int & cnt){
        if(root==nullptr) return {0,0};
        P l = dfs(root->left, cnt);
        P r = dfs(root->right, cnt);
        int sum = l.second + r.second + root->val;
        int n   = l.first + r.first + 1;
        if((sum/n)==root->val) cnt++;
        return {n, sum};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

