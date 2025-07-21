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
    string getNode(TreeNode* node, vector<string> &path, int value){
        if(node == NULL) return "";
        if(node->val == value){
            string out = "";
            for(auto x:path) out += x;
            return out;
        }
        path.push_back("L");
        string res;
        res = getNode(node->left,path,value);
        if(res!="") return res;
        path.pop_back();
        path.push_back("R");
        res = getNode(node->right,path,value);
        if(res!="") return res;
        path.pop_back();
        return "";
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<string> start;
        vector<string> dest;
        string start_path = getNode(root,start,startValue);
        string dest_path = getNode(root,dest,destValue);
        int i=0;
        while(i<start_path.length() && i<dest_path.length()){
            if(start_path[i]==dest_path[i]) i++;
            else break;
        }
        int j=i;
        string out = "";
        while(i<start_path.length()){
            out += 'U';
            i++;
        }
        while(j<dest_path.length()){
            out += dest_path[j];
            j++;
        }
        return out;
    }
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* st=nullptr;
    TreeNode* dt=nullptr;
    void dfs(TreeNode* root, int startValue, int destValue){
        if(root==nullptr) return;
        dfs(root->left, startValue, destValue);
        dfs(root->right, startValue, destValue);
        if(root->val==startValue) st = root;
        else if(root->val==destValue) dt = root;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        parent.clear();
        dfs(root, startValue, destValue);
        queue<pair<TreeNode*, string>> q;
        q.push(make_pair(st,""));
        while(!q.empty()){
            auto [node, s] = q.front();
            q.pop();
            if(node==dt){
                return s;
            }
            if(node->left!=nullptr) q.push(make_pair(node->left, s+"L"));
            if(node->right!=nullptr) q.push(make_pair(node->right, s+"R"));
            if(parent.find(node)!=parent.end()) q.push(make_pair(parent[node], s+"U"));
        }
        return "";
    }
};

class Solution {
public:
    TreeNode* lca(TreeNode* root, int p, int q){
        if(root==nullptr || root->val == p || root->val == q) return root;
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);
        if(left && right) return root;
        if(!left && !right) return nullptr;
        if(left) return left;
        return right;
    }
    bool dfs(TreeNode* root, int val, string& curr){
        if(root==nullptr) return false;;
        if(root->val==val){
            return true;
        }
        curr.push_back('L');
        bool left = dfs(root->left, val, curr);
        if(left) return true;
        curr.pop_back();
        curr.push_back('R');
        bool right = dfs(root->right, val, curr);
        if(right) return true;
        curr.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* anc = lca(root, startValue, destValue);
        string pathSrc = "";
        string pathDest = "";
        dfs(anc, startValue, pathSrc);
        dfs(anc, destValue, pathDest);
        for(int i=0;i<pathSrc.size();i++){
            pathSrc[i] = 'U';
        }
        return pathSrc + pathDest;
    }
};

class Solution {
public:
    bool dfs(TreeNode* root, int val, string& curr){
        if(root==nullptr) return false;;
        if(root->val==val){
            return true;
        }
        curr.push_back('L');
        bool left = dfs(root->left, val, curr);
        if(left) return true;
        curr.pop_back();
        curr.push_back('R');
        bool right = dfs(root->right, val, curr);
        if(right) return true;
        curr.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathSrc = "";
        string pathDest = "";
        dfs(root, startValue, pathSrc);
        dfs(root, destValue, pathDest);
        string res = "";
        int l = 0;
        while(l<pathSrc.size() && l<pathDest.size() && pathSrc[l]==pathDest[l]) l++;
        for(int i=0;i<pathSrc.size()-l;i++){
            res.push_back('U');
        }
        res += pathDest.substr(l);
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}

