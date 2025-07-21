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
    string lexo = "";
    void dfs(TreeNode* root, string curr){
        if(root==nullptr){
            return;
        }
        char r = (root->val) + 'a';
        curr = r + curr;
        if(root->left==nullptr && root->right==nullptr){
            if(lexo=="") lexo = curr;
            else lexo = (lexo>curr)?curr:lexo;
            return;
        }
        dfs(root->left, curr);
        dfs(root->right, curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return lexo;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

