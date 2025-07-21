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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll maxW = 0;
        while(!q.empty()){
            int size = q.size();
            ll width = q.back().second - q.front().second;
            for(int i=0;i<size;i++){
                auto [node,idx] = q.front();
                q.pop();
                if(node->left!=nullptr) q.push({node->left, 2*idx+1});
                if(node->right!=nullptr) q.push({node->right, 2*idx+2});
            }
            maxW = max(maxW, width+1);
        }
        return maxW;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

