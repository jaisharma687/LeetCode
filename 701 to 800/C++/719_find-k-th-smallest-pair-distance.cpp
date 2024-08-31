#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;


//Brute Force
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dist;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dist.push_back(abs(nums[i]-nums[j]));
            }
        }
        sort(dist.begin(),dist.end());
        return dist[k-1];
    }
};

//Max Heap
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                pq.push(abs(nums[i]-nums[j]));
                while(pq.size()>k) pq.pop();
            }
        }
        return pq.top();
    }
};

//Hash map
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                m[abs(nums[i]-nums[j])]++;
            }
        }
        for(auto x:m){
            k-=x.second;
            if(k<=0) return x.first;
        }
        return -1;
    }
};

//vector map
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int m = *max_element(nums.begin(),nums.end());
        vector<int> dist(m+1,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dist[abs(nums[i]-nums[j])]++;
            }
        }
        for(int i=0;i<m+1 && k>0;i++){
            k-=dist[i];
            if(k<=0) return i;
        }
        return -1;
    }
};

//sliding window and binary search
class Solution {
public:
    int pairCount(vector<int>& nums, int dist){
        int i=0;
        int j=1;
        int count = 0;
        while(j<nums.size()){
            while(nums[j]-nums[i]>dist) i++;
            count += j-i;
            j++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int l = 0;
        int h = nums[n-1]-nums[0];
        int res = 0;
        while(l<=h){
            int mid = (l+h)/2;
            int count = pairCount(nums,mid);
            if(count<k) l=mid+1;
            else{
                h=mid-1;
                res = mid;
            }
        }
        return res;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}