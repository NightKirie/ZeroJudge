#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define int long long
#define N 300005
#define Orz ios::sync_with_stdio(0),cin.tie(0)
#define INF 2e18
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define all(x) x.begin(),x.end()
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
int n,arr[N],pref[N];
pii sorted[N];

signed main(){
    Orz;
    cin>>n;
    rep(i,1,n){
        cin>>sorted[i-1].x;
        arr[i] = sorted[i-1].x;
        sorted[i-1].y = i;
        pref[i] = pref[i-1]+arr[i];
    }
    sort(sorted,sorted+n);
    int ind = 0,l = 1,r = n;

    while(r>l){
        while(sorted[ind].y > r || sorted[ind].y < l)ind++;
        int left = pref[sorted[ind].y-1]-pref[l-1];
        int right = pref[r]-pref[sorted[ind].y];
        if(left > right){
            r = sorted[ind].y-1;
        }
        else{
            l = sorted[ind].y+1;
        }
    }
    cout<<arr[l]<<endl;
}