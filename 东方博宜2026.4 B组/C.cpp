#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll a,b,c,ax,bx,cx,ans1,ans,mx,type=0;
void solve(){
    cin>>a>>b>>c;
    cx=mx=c;
    if(a==b&&a==c){
        cout<<a<<"\n0";
        return;
    }
    while(type<2){
        if(type==0){
            ll k=min(b,cx);
            bx+=k;
            cx-=k;
            ans1++;
            if (bx && (bx < mx || bx == mx && ans1 < ans))
                mx = bx, ans = ans1;
            if (ax && (ax < mx || ax == mx && ans1 < ans))
                mx = ax, ans = ans1;
            if (cx && (cx < mx || cx == mx && ans1 < ans))
                mx = cx, ans = ans1;
            if (st.find(ax * 5000 + bx) == st.end())
            {
                st.insert(ax * 5000 + bx);
            }
            else
                type = 2;
            if (type == 0)
                type = 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}