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
    int idx;
    int findIdx(int val, vector<int>& inorder){
        for(int i=0;i<inorder.size();i++) if(val==inorder[i]) return i;
        return -1;
    }
    TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int start, int end){
        if(start>end) return nullptr;
        int rootVal = postorder[idx];
        int i = findIdx(rootVal, inorder);
        idx--;
        TreeNode* root = new TreeNode(rootVal);
        root->right = construct(inorder, postorder, i+1, end);
        root->left = construct(inorder, postorder, start, i-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        idx = n-1;
        return construct(inorder, postorder, 0, n-1);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

