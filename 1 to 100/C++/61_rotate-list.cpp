#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(head==nullptr || head->next==nullptr || k==0) return head;
            int l = 1;
            ListNode* tail = head;
            while(tail->next!=nullptr){
                tail = tail->next;
                l++;
            }
            k = k % l;
            if(k==0) return head;
            tail->next = head;
            // newHead is at l-k, so we need to change the link between the l-k-1 (newTail) and l-k (newHead) node so, newTailShift should be l-k-1
            int newTailShift = l - k - 1;
            ListNode* newTail = head;
            while(newTailShift ){
                newTail = newTail->next;
                newTailShift--;
            }
            head = newTail->next;
            newTail->next = nullptr;
            return head;
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