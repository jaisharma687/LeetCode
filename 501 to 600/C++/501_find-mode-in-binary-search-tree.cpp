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
    vector<int> res;
    int maxFreq = 0;
    int currFreq = 0;
    int curr = 0;
    void inorder(TreeNode* root, int prev){
        if(root==nullptr) return;
        if(root->left) inorder(root->left, prev);
        prev = root->val;
        if(curr==root->val){
            currFreq++;
        }else{
            curr = root->val;
            currFreq = 1;
        }
        if(currFreq>maxFreq){
            res = {root->val};
            maxFreq = currFreq;
        }
        else if(currFreq==maxFreq){
            res.push_back(root->val);
        }
        if(root->right) inorder(root->right, root->val);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root, -1);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

