#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class CustomStack {
public:
    stack<int> st;
    int sz;
    CustomStack(int maxSize) {
        sz = maxSize;
    }
    
    void push(int x) {
        if(st.size()!=sz){
            st.push(x);
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        int res = st.top();
        st.pop();
        return res;
    }
    
    void increment(int k, int val) {
        stack<int> inc;
        while(!st.empty()){
            inc.push(st.top());
            st.pop();
        }
        int incSz = inc.size();
        for(int i=0;i<min(incSz,k);i++){
            st.push(inc.top()+val);
            inc.pop();
        }
        while(!inc.empty()){
            st.push(inc.top());
            inc.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();