#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;


//Definition for a binary tree node.
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
        int maxDiameter = 0;
        int depth(TreeNode* root){
            if(root==nullptr){
                return 0;
            }
            int left_max = depth(root->left);
            int right_max = depth(root->right);
            maxDiameter = max(maxDiameter,left_max+right_max);
            return 1 + max(left_max,right_max);
        }
        int diameterOfBinaryTree(TreeNode* root) {
            depth(root);
            return maxDiameter;
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();