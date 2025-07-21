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

class FindElements {
public:
    unordered_map<int, bool> mpp;
    FindElements(TreeNode* root) {
        root->val = 0;
        mpp[0] = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto node = q.front();
                mpp[node->val] = true;
                q.pop();
                if(node->left){
                    q.push(node->left);
                    node->left->val = 2*node->val + 1;
                }
                if(node->right){
                    q.push(node->right);
                    node->right->val = 2*node->val + 2;
                }
            }
        }
    }

    bool find(int target) {
        return mpp[target];
    }
};

class FindElements {
public:
    unordered_set<int> set;
    FindElements(TreeNode* root) {
        root->val = 0;
        set.insert(0);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto node = q.front();
                set.insert(node->val);
                q.pop();
                if(node->left){
                    q.push(node->left);
                    node->left->val = 2*node->val + 1;
                }
                if(node->right){
                    q.push(node->right);
                    node->right->val = 2*node->val + 2;
                }
            }
        }
    }

    bool find(int target) {
        if(set.find(target)==set.end()) return false;
        return true;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    TreeNode* root;
    FindElements* obj = new FindElements(root);
}

