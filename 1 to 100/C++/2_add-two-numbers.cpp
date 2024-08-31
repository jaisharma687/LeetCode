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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* res = new ListNode();
        ListNode* head = res;
        int carry = 0;
        while(t1 != NULL && t2 != NULL){
            int rem = (t1->val + t2->val + carry)%10;
            res->next = new ListNode(rem);
            carry = (t1->val + t2->val + carry)/10;
            res = res->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1!=NULL){
            res->next = new ListNode((t1->val + carry)%10);
            carry = (t1->val + carry)/10;
            res = res->next;
            t1 = t1->next;
        }
        while(t2!=NULL){
            res->next = new ListNode((t2->val + carry)%10);
            carry = (t2->val + carry)/10;
            res = res->next;
            t2 = t2->next;
        }
        if(carry) res->next = new ListNode(carry);
        return head->next;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}