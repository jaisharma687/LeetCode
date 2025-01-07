#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next == NULL){
            return {-1,-1};
        }
        ListNode* current = head;
        ListNode* prev = new ListNode();
        ListNode* nxt = current->next;
        vector<int> arr;
        int i = 0;
        while(nxt!=NULL){
            i++;
            if(((current->val > nxt-> val && current->val > prev->val)||
            (current->val < nxt-> val && current->val < prev->val)) && prev->val != 0){
                arr.push_back(i);
            }
            prev = current;
            current = nxt;
            nxt = nxt->next;
        }
        vector<int> diff;
        if(arr.size()<=1) return {-1,-1};
        for(int i=1;i<arr.size();i++){
            diff.push_back(arr[i]-arr[i-1]);
        }
        sort(diff.begin(),diff.end());
        return {diff[0], arr[arr.size()-1]-arr[0]};
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}