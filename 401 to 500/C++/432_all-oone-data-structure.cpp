#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class AllOne {
public:
    struct DList {
        int count;
        set<string> keys;
        DList* next;
        DList* prev;
    };

    DList* head;
    DList* tail;
    unordered_map<string, DList*> nodeMap;

    DList* createNode(string key, int count) {
        DList* node = new DList();
        node->keys.insert(key);
        node->count = count;
        node->next = nullptr;
        node->prev = nullptr;
        return node;
    }

    AllOne() {
        head = createNode("", 0);
        tail = createNode("", INT_MAX);
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (nodeMap.find(key) == nodeMap.end()) {
            if (head->next->count != 1) {
                DList* newNode = createNode(key, 1);
                newNode->next = head->next;
                head->next->prev = newNode;
                head->next = newNode;
                newNode->prev = head;
                nodeMap[key] = newNode;
            } else {
                head->next->keys.insert(key);
                nodeMap[key] = head->next;
            }
        } else {
            DList* node = nodeMap[key];
            node->keys.erase(key);
            if (node->next->count == node->count + 1) {
                node->next->keys.insert(key);
                nodeMap[key] = node->next;
            } else {
                DList* newNode = createNode(key, node->count + 1);
                newNode->next = node->next;
                node->next->prev = newNode;
                newNode->prev = node;
                node->next = newNode;
                nodeMap[key] = newNode;
            }

            if (node->keys.empty()) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                delete node;
            }
        }
    }

    void dec(string key) {
        DList* node = nodeMap[key];
        if (node->count == 1) {
            node->keys.erase(key);
            nodeMap.erase(key);
            if (node->keys.empty()) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                delete node;
            }
        } else {
            node->keys.erase(key);
            if (node->prev->count == node->count - 1) {
                node->prev->keys.insert(key);
                nodeMap[key] = node->prev;
            } else {
                DList* newNode = createNode(key, node->count - 1);
                newNode->prev = node->prev;
                newNode->next = node;
                node->prev->next = newNode;
                node->prev = newNode;
                nodeMap[key] = newNode;
            }
            if (node->keys.empty()) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                delete node;
            }
        }
    }

    string getMaxKey() {
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        return *(head->next->keys.begin());
    }
};

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();