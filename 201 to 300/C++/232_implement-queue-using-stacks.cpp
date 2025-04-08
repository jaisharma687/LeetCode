#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class MyQueue {
    public:
        stack<int> s1,s2;
        MyQueue() {
            
        }
        
        void push(int x) {
            s1.push(x);
        }
        
        int pop() {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int val = s2.top();
            s2.pop();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            return val;
        }
        
        int peek() {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int val = s2.top();
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
            return val;
        }
        
        bool empty() {
            return s1.empty();
        }
    };
    
    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue* obj = new MyQueue();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->peek();
     * bool param_4 = obj->empty();
     */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    MyQueue obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();