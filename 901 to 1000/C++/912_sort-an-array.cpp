#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int mod = 1e9+7;

class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(vector<int>& arr, int low, int high){
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i < j){
            while(arr[i] <= pivot && i < high) i++;
            while(arr[j] > pivot) j--;
            if(i < j) swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }
    
    int randomPartition(vector<int>& arr, int low, int high){
        int r = low + rand() % (high - low + 1);
        swap(arr[r], arr[low]);
        return partition(arr, low, high);
    }
    
    void quicksort(vector<int>& arr, int low, int high){
        if(low < high){
            int p = randomPartition(arr, low, high);
            quicksort(arr, low, p - 1);
            quicksort(arr, p + 1, high);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size() - 1);
        return nums;
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    Solution obj;
}