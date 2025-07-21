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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        int i = 0;
        while(i<n && traversal[i]>='0' && traversal[i]<='9') i++;
        TreeNode* root = new TreeNode(stoi(traversal.substr(0,i)));
        int j;
        stack<TreeNode*> st;
        st.push(root);
        while(i<n){
            int d = 0;
            while(i<n && traversal[i]=='-'){
                i++;
                d++;
            }
            j = i;
            while(j<n && traversal[j]>='0' && traversal[j]<='9') j++;
            int val = stoi(traversal.substr(i,j-i));
            i = j;
            while(st.size()>d) st.pop();
            TreeNode* parent = st.top();
            TreeNode* newNode = new TreeNode(val);
            if(parent->left) parent->right = newNode;
            else parent->left = newNode;
            st.push(newNode);
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* solve(string& traversal,int& n, int& i, int depth){
        if(i>=n) return nullptr;
        int j = i;
        while(j<n && traversal[j]=='-') j++;
        int dash = j-i;
        if(dash!=depth) return nullptr;
        i = j;
        while(i<n && traversal[i]>='0' && traversal[i]<='9') i++;
        TreeNode* node = new TreeNode(stoi(traversal.substr(j,i-j)));
        node->left = solve(traversal, n, i, depth+1);
        node->right = solve(traversal, n, i, depth+1);
        return node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i = 0;
        int n = traversal.size();
        return solve(traversal, n, i, 0);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

