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


// class Solution {
// public:
//     void insertNode(ListNode* tail, ListNode* node){
//         node->next = tail->next;
//         tail->next = node;
//         return;
//     }
//     ListNode* deleteNode(ListNode* node, ListNode* prev){
//         prev->next = node->next;
//         node->next = nullptr;
//         return node;
//     }
//     ListNode* oddEvenList(ListNode* head) {
//         if(head==nullptr || head->next==nullptr){
//             return head;
//         }
//         int l = 1;
//         ListNode* tail = head;
//         ListNode* prev = nullptr;
//         while(tail->next!=nullptr){
//             prev = tail;
//             tail = tail->next;
//             l++;
//         }
//         if(l%2==0){
//             tail=prev;
//         }
//         ListNode* even = head->next;
//         ListNode* odd = head;
//         ListNode* lastOdd = tail;
//         while(odd!=lastOdd){
//             ListNode* temp = even;
//             temp = deleteNode(temp,odd);
//             odd = odd->next;
//             even = odd->next;
//             insertNode(tail,temp);
//             tail = tail->next;
//         }
//         return head;
//     }
// };

// More oprimized Code
class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            if(head==nullptr || head->next==nullptr){
                return head;
            }
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenHead = even;
            while(even && even->next){
                odd->next = even->next;
                odd = odd->next;
                even->next = odd->next;
                even = odd->next;
            }
            odd->next = evenHead;
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