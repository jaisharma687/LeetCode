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
        int minDepth(TreeNode* root) {
            if(root==nullptr){
                return 0;
            }
            int level = 0;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                level++;
                int l = q.size();
                for(int i=0;i<l;i++){
                    auto node = q.front();
                    q.pop();
                    if(node->left == nullptr && node->right == nullptr){
                        return level;
                    }
                    if(node->left!=nullptr) q.push(node->left);
                    if(node->right!=nullptr) q.push(node->right);
                }
            }
            return -1;
        }
    };

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        if(!(root->left) && !(root->right)) return 1;
        int lh = INT_MAX;
        int rh = INT_MAX;
        if(root->left)  lh = minDepth(root->left);
        if(root->right) rh = minDepth(root->right);
        return 1 + min(lh,rh);
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