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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int preStart, int postStart, int preEnd){
        if(preEnd < preStart) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart==preEnd) return root;
        int nextNode = preorder[preStart+1];
        int j = postStart;
        while(postorder[j]!=nextNode) j++;
        int num = j - postStart + 1;
        root->left = solve(preorder, postorder, preStart+1, postStart, preStart+num);
        root->right = solve(preorder, postorder, preStart+num+1, j+1, preEnd);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return solve(preorder, postorder, 0,0, preorder.size()-1);
    }
};

class Solution {
public:
    unordered_map<int, int> mpp;
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder, int preStart, int postStart, int preEnd){
        if(preEnd < preStart) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart==preEnd) return root;
        int nextNode = preorder[preStart+1];
        int j = mpp[nextNode];
        int num = j - postStart + 1;
        root->left = solve(preorder, postorder, preStart+1, postStart, preStart+num);
        root->right = solve(preorder, postorder, preStart+num+1, j+1, preEnd);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++) mpp[postorder[i]] = i;
        return solve(preorder, postorder, 0,0, preorder.size()-1);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

