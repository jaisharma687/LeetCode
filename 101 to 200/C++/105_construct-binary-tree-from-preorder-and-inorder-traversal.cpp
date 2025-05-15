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
    private:
        int idx;
    public:
        int findIdx(vector<int>& inorder, int val){
            for(int i=0;i<inorder.size();i++){
                if(inorder[i]==val) return i;
            }
            return -1;
        }
        TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int start, int end){
            if(start>end){
                return NULL;
            }
            int rootVal = preorder[idx];
            int i = findIdx(inorder, rootVal);
            idx++;
            TreeNode* root = new TreeNode(rootVal);
            root->left = construct(preorder, inorder, start, i-1);
            root->right = construct(preorder, inorder, i+1, end);
            return root;
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            int n = preorder.size();
            idx = 0;
            return construct(preorder, inorder, 0, n-1);
        }
    };

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

