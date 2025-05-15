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
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    int height(map<int,vector<int>>& mpp, TreeNode* root){
        if(root==nullptr) return 0;
        int lh = height(mpp, root->left);
        int rh = height(mpp, root->right);
        int h = 1 + max(lh, rh);
        mpp[h].push_back(root->val);
        return h;
    }
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here
        map<int,vector<int>> mpp;
        height(mpp, root);
        vector<vector<int>> res;
        for(auto m: mpp){
            res.push_back(m.second);
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

