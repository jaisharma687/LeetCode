#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    void split(string query, char separator, vector<string> &ip){
        int start = 0; int end = 0;
        for(int i=0;i<=query.size();i++){
            if(query[i] == separator || i==query.size()){
                end = i;
                ip.push_back(query.substr(start,end-start));
                start = end + 1;
            }
        }
    }
    bool validateIPv4(vector<string> ipv4){
        if(ipv4.size()==1 || ipv4.size() != 4) return false;
        for(int i=0;i<4;i++){
            if(ipv4[i].size()==0) return false;
            if(ipv4[i][0] == '0' && ipv4[i].size()>1) return false;
            for(int j=0; j<ipv4[i].size();j++){
                if(ipv4[i][j] != '0' && ipv4[i][j] != '1' && ipv4[i][j] != '2' 
                && ipv4[i][j] != '3' && ipv4[i][j] != '4' && ipv4[i][j] != '5' 
                && ipv4[i][j] != '6' && ipv4[i][j] != '7' && ipv4[i][j] != '8' 
                && ipv4[i][j] != '9') return false;
            }
            if(ipv4[i].length()>3) return false;
            if(stoi(ipv4[i])>255 || stoi(ipv4[i])<0) return false;
        }
        return true;
    }
    bool validateIPv6(vector<string> ipv6){
        if(ipv6.size()==1 || ipv6.size() != 8) return false;
        for(int i=0;i<8;i++){
            if(ipv6[i].size()==0) return false;
            if(ipv6[i].length()>4) return false;
            for(int j = 0 ;j<ipv6[i].length();j++){
                if(ipv6[i][j] != '0' && ipv6[i][j] != '1' && ipv6[i][j] != '2' 
                && ipv6[i][j] != '3' && ipv6[i][j] != '4' && ipv6[i][j] != '5' 
                && ipv6[i][j] != '6' && ipv6[i][j] != '7' && ipv6[i][j] != '8' 
                && ipv6[i][j] != '9' && ipv6[i][j] != 'a' && ipv6[i][j] != 'b' 
                && ipv6[i][j] != 'c' && ipv6[i][j] != 'd' && ipv6[i][j] != 'e' 
                && ipv6[i][j] != 'f' && ipv6[i][j] != 'A' && ipv6[i][j] != 'B' 
                && ipv6[i][j] != 'C' && ipv6[i][j] != 'D' && ipv6[i][j] != 'E' 
                && ipv6[i][j] !='F') return false;
            }
        }
        return true;
    }
    string validIPAddress(string queryIP) {
        vector<string> ipv4;
        split(queryIP,'.',ipv4);
        vector<string> ipv6;
        split(queryIP,':',ipv6);
        bool a = validateIPv4(ipv4);
        bool b = validateIPv6(ipv6);
        if(!a && !b) return "Neither";
        else if(a) return "IPv4";
        else return "IPv6";
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}