#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
set<ll> st;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll op,x;
        cin>>op>>x;
        if(op==1){
            if(st.count(x)) cout<<"Already Exist"<<el;
            else st.insert(x);
        }else{
            if(st.empty()) cout<<"Empty"<<el;
            else{
                auto pos=st.lower_bound(x);
                if(st.size()>=1&&pos==st.end()){
                    cout<<*(--pos)<<el;
                    st.erase(pos);
                    continue;
                }else if(pos==st.begin()){
                    cout<<*pos<<el;
                    st.erase(pos);
                    continue;
                }
                if(*pos==x){cout<<x<<el;st.erase(pos);}
                else{
                    auto pos2=pos;
                    pos--;
                    ll x1=*pos,x2=*pos2;
                    if(abs(x1-x)>abs(x2-x)){
                        cout<<x2<<el;
                        st.erase(pos2);
                    }else{
                        cout<<x1<<el;
                        st.erase(pos);
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}