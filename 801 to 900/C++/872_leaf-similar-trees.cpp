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

// class Solution {
// public:
//     int height(TreeNode* root, vector<int>& res){
//         if(root==nullptr) return 0;
//         int lh = height(root->left,res);
//         int rh = height(root->right,res);
//         int h = 1 + max(lh,rh);
//         if(h==1) res.push_back(root->val);
//         return h;
//     }
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) {
//         vector<int> r1, r2;
//         height(root1, r1);
//         height(root2, r2);
//         return r1==r2;
//     }
// };

class Solution {
public:
    int height(TreeNode* root, string& res){
        if(root==nullptr) return 0;
        int lh = height(root->left,res);
        int rh = height(root->right,res);
        int h = 1 + max(lh,rh);
        if(h==1) res = res + to_string(root->val) + "#";
        return h;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string r1 = "";
        string r2 = "";
        height(root1, r1);
        height(root2, r2);
        return r1==r2;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

