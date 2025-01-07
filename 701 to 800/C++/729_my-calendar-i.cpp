#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class MyCalendar {
public:
    set<pair<int,int>> cal;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = cal.lower_bound({start,end});
        if(it!=cal.end() && it->first<end) return false;
        if(it!=cal.begin()){
            auto prevIt = prev(it);
            if(start < prevIt->second) return false;
        }
        cal.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();