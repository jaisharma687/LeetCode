#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

bool checkArmstrong(int n){
	//Write your code here
	int d = (int)(log10(n)+1);
	int p = n;
	long val = 0;
	while(p>0){
		val += pow(p%10,d);
		p/=10;
	}
	return val==n;
}


static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();