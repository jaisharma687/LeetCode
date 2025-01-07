#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}