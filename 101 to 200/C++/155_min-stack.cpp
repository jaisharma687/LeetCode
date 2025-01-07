#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class MinStack {
public:
    stack<int> st;
    stack<int> minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minStack.empty()) minStack.push(val);
        else minStack.push(min(val,minStack.top()));
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();