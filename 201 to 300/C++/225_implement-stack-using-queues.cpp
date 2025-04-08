#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class MyStack {
    public:
        queue<int> q;
        MyStack() {
            
        }
        
        void push(int x) {
            int s = q.size();
            q.push(x);
            for(int i=0;i<s;i++){
                q.push(q.front());
                q.pop();
            }
        }
        
        int pop() {
            int val = q.front();
            q.pop();
            return val;
        }
        
        int top() {
            return q.front();
        }
        
        bool empty() {
            return q.empty();
        }
    };
    
    /**
     * Your MyStack object will be instantiated and called as such:
     * MyStack* obj = new MyStack();
     * obj->push(x);
     * int param_2 = obj->pop();
     * int param_3 = obj->top();
     * bool param_4 = obj->empty();
     */

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    MyStack obj;
}

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();