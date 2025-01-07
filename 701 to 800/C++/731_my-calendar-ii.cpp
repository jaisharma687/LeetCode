#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class MyCalendarTwo {
public:
    vector<pair<int,int>> doubleBook;
    vector<pair<int,int>> booking;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto bk: doubleBook){
            if(max(start,bk.first)<min(end,bk.second)) return false;
        }
        for(auto bk: booking){
            if(max(start,bk.first)<min(end,bk.second)){
                doubleBook.push_back({max(start,bk.first),min(end,bk.second)});
            }
        }
        booking.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();