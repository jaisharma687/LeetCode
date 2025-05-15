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
    const int mod = 1e9 + 7;
    int totalSum(TreeNode* root){
        if(root==nullptr) return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }
    long long maxPdt = 0;
    int findMaxPdt(TreeNode* root, const int totalSum){
        if(root==nullptr) return 0;
        int lh = findMaxPdt(root->left, totalSum);
        int rh = findMaxPdt(root->right, totalSum);
        int sum = lh+rh+root->val;
        maxPdt = max(maxPdt, (long long)(totalSum-sum)*(sum));
        return sum;
    }
    int maxProduct(TreeNode* root) {
        findMaxPdt(root, totalSum(root));
        return (int)((maxPdt)%mod);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

