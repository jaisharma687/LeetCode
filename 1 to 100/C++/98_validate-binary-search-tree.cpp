#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<long int>& out){
        if(root==NULL) return;
        inorder(root->left,out);
        out.push_back(root->val);
        inorder(root->right,out);
    }
    bool isValidBST(TreeNode* root) {
        vector<long int> res;
        inorder(root,res);
        bool inc = true;
        for(int i=1;i<res.size() && inc == true;i++){
            if(res[i]-res[i-1] <= 0) inc = false;
        }
        return inc;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}