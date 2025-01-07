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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            n++;
        }
        int r = n % k;
        int s = n / k;
        temp = head;
        vector<ListNode*> res;
        while(r>0){
            ListNode t = ListNode(0,temp);
            ListNode* p = &t;
            for(int i=0;i<s+1;i++){
                p = p->next;
            }
            temp = p->next;
            p->next = nullptr;
            res.push_back(t.next);
            r--;
            k--;
        }
        while(k>0){
            if(temp==nullptr){
                res.push_back(nullptr);
            }
            else{
                ListNode t = ListNode(0,temp);
                ListNode* p = &t;
                for(int i=0;i<s;i++){
                    p = p->next;
                }
                temp = p->next;
                p->next = nullptr;
                res.push_back(t.next);
            }
            k--;
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}