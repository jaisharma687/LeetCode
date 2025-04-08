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
        ListNode* reverse(ListNode* list){
            ListNode* curr = list;
            ListNode* prev = nullptr;
            while(curr){
                ListNode* newNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = newNode;
            }
            return prev;
        }
        bool isPalindrome(ListNode* head) {
            if(head==nullptr || head->next == nullptr){
                return true;
            }
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* rev = reverse(slow);
            while(rev!=nullptr){
                if(head->val != rev->val) return false;
                head = head->next;
                rev = rev->next;
            }
            return true;
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