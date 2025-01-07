#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class MyCircularDeque {
public:
    deque<int> d;
    int sz;
    MyCircularDeque(int k) {
        sz = k;
    }
    
    bool insertFront(int value) {
        if(d.size()<sz){
            d.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(d.size()<sz){
            d.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(d.size()>0){
            d.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(d.size()>0){
            d.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(d.size()==0){
            return -1;
        }
        return d.front();
    }
    
    int getRear() {
        if(d.size()==0){
            return -1;
        }
        return d.back();
    }
    
    bool isEmpty() {
        return d.empty();
    }
    
    bool isFull() {
        return d.size()==sz;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();