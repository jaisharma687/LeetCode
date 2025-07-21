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
//     int maxZZ = 0;
//     void maxZigZag(TreeNode* root, bool left, int curr){
//         if(root == nullptr) return;
//         maxZZ = max(maxZZ, curr);
//         if(left){
//             maxZigZag(root->left, false, curr+1);
//             maxZigZag(root->right, true, 1);
//         }else{
//             maxZigZag(root->right, true, curr+1);
//             maxZigZag(root->left, false, 1);
//         }
//     }
//     int longestZigZag(TreeNode* root) {
//         maxZigZag(root,false, 0);
//         maxZigZag(root,true, 0);
//         return maxZZ;
//     }
// };

class Solution {
public:
    int maxZZ = 0;
    void maxZigZag(TreeNode* root, int l, int r){
        if(root==nullptr) return;
        maxZZ = max({maxZZ,l,r});
        maxZigZag(root->left, r+1, 0);
        maxZigZag(root->right, 0, l+1);
    }
    int longestZigZag(TreeNode* root) {
        maxZigZag(root, 0, 0);
        return maxZZ;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

