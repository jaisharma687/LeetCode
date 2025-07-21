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
    void inorder(TreeNode* root,int& prev, int& minDiff){
        if(root==nullptr) return;
        if(root->left) inorder(root->left,prev, minDiff);
        if(prev!=-1) minDiff = min(minDiff, abs(root->val - prev));
        prev = root->val;
        if(root->right) inorder(root->right,prev, minDiff);
    }
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        int prev = -1;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

