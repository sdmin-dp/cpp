#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
void solve(){
    cin>>n>>m;
    double s1,e1,h1;
    cin>>s1>>e1>>h1;
    for(int i=1;i<=n;i++){
        ll s2,e2,h2;
        cin>>s2>>e2>>h2;
        // cout<<s2<<" "<<e2<<" "<<h2<<el;
        if(abs(h2-h1)>m) cout<<"No\n";
        else if((e2-s2)==(e1-s1)){
            // cerr<<s2<<" "<<e2<<" "<<h2<<el;
            // cerr<<(e2-s2)<<" "<<(e1-s1)<<el;
            if(s2==s1) cout<<"Always\n";
            else  cout<<"No\n";
        }
        else{
            // cout<<"dog"<<el;
            double x=(s2-s1)*1.0/((e1-s1)-(e2-s2));//cerr<<x<<el;
            if(x>=0&&x<=1) printf("%.12lf\n",s1+(e1-s1)*x);
            else cout<<"No\n";
        }                                                                
    }
}

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}