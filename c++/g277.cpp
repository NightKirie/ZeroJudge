#include <bits/stdc++.h>
#define MAX_N 300005
#define MAX_A 10000000
#define a first 
#define idx second 
#define ll long long
using namespace std;

int n, temp;
pair<int, int> sort_arr[MAX_N];
ll acc[MAX_N] = {0};

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> sort_arr[i].a;
        sort_arr[i].idx = i;
        acc[i+1] = acc[i] + sort_arr[i].a;
    }
    sort(sort_arr, sort_arr + n);
    int l = 0, r = n-1, i = 0;
    
    while(r > l) {
        while(sort_arr[i].idx > r || sort_arr[i].idx < l)
            ++i;
        
        ll sum_l = acc[sort_arr[i].idx] - acc[l]; 
        ll sum_r = acc[r+1] - acc[sort_arr[i].idx+1];
        
        if(sum_l > sum_r){
            r = sort_arr[i].idx - 1;
        }
        else{
            l = sort_arr[i].idx + 1;
        }
    }
    cout << acc[r+1] - acc[r] << "\n";

}