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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==nullptr || root==p || root==q){
//             return root;
//         }
//         auto left = lowestCommonAncestor(root->left,p,q);
//         auto right = lowestCommonAncestor(root->right,p,q);
//         if(left==nullptr && right==nullptr) return nullptr;
//         if(left!=nullptr && right!=nullptr) return root;
//         return left==nullptr?right:left;
//     }
// };

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            while(root){
                if(min(p->val,q->val)>root->val){
                    root = root->right;
                }
                else if(max(p->val,q->val)<root->val){
                    root = root->left;
                }
                else return root;
            }
            return nullptr;
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