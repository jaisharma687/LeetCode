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
    ListNode* reverseLL(ListNode* l){
        ListNode* prev = nullptr;
        ListNode* current = l;
        ListNode* nxt;
        while(current!=nullptr){
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        ListNode* out = new ListNode();
        ListNode* t = out;
        int carry = 0;
        while(t1!= nullptr && t2!= nullptr){
            int v1 = t1->val;
            int v2 = t2->val;
            ListNode* temp = new ListNode((v1+v2+carry)%10);
            t->next = temp;
            carry = (v1+v2+carry)/10;
            t1 = t1->next;
            t2 = t2->next;
            t = t->next;
        }
        while(t1!=nullptr){
            int v1 = t1->val;
            ListNode* temp = new ListNode((v1+carry)%10);
            t->next = temp;
            carry = (v1+carry)/10;
            t1 = t1->next;
            t = t->next;
        }
        while(t2!=nullptr){
            int v2 = t2->val;
            ListNode* temp = new ListNode((v2+carry)%10);
            t->next = temp;
            carry = (v2+carry)/10;
            t2 = t2->next;
            t = t->next;
        }
        if(carry){
            t->next = new ListNode(carry);
        }
        return reverseLL(out->next);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}