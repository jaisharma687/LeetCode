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

// TC: O(n), SC: O(w)
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth, int currDepth=1) {
        if(depth==1){
            return new TreeNode(val, root, nullptr);
        }
        if(root==nullptr){
            return nullptr;
        }
        if(currDepth == depth - 1){
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
            return root;
        }
        root->left = addOneRow(root->left, val, depth, currDepth+1);
        root->right = addOneRow(root->right, val, depth, currDepth+1);
        return root;
    }
};

// TC: O(log n * log n), SC: O(log n)
class Solution {
public:
    int getRoot(TreeNode* root, bool left){
        int h = 0;
        TreeNode* temp = root;
        if(left){
            while(temp!=nullptr){
                temp = temp->left;
                h++;
            }
        }else{
            while(temp!=nullptr){
                temp = temp->right;
                h++;
            }
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int lh = getRoot(root, true);
        int rh = getRoot(root, false);
        if(lh==rh) return (int)(pow(2,lh))-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

