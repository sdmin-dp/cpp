#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
/*
第奇数行第奇数列的字符为 +。
第奇数行第偶数列的字符为 -。
第偶数行第奇数列的字符为 |。
第偶数行第偶数列的字符为空格。
*/
void solve(){
    cin>>n>>m;
    for(int i=1;i<=2*n+1;i++){
        for(int j=1;j<=2*m+1;j++){
            if(i%2&&j%2) cout<<'+';
            if(i%2&&j%2==0) cout<<'-';
            if(i%2==0&&j%2) cout<<'|';
            if(i%2==0&&j%2==0) cout<<' ';
            
        }
        cout<<el;
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