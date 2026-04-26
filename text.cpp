#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll A,B,C;
ll a,b,c;
ll hsh(pair<ll,ll> a){
    return a.first*10000+a.second;
}
pair<ll,ll> rehsh(ll a){
    return {a%10000,a/10000};
}
unordered_set<ll> st;
void solve(){
    cin>>A>>B>>C;
    if(A==B&&B==C){
        cout<<A<<"\n"<<0;
        return;
    }
    a=0,b=0,c=C;
    ll ans=0,mn=1e12,cnt=0;
    ll ans2=0,mn2=1e12;
    while(st.find(hsh({a,b}))==st.end()){
        st.insert(hsh({a,b}));
        cnt++;
        if(b==0){
            if(c<B) b=c,c=0;
            else c-=B,b=B;
        }else if(b!=0){
            if(a==A) c+=a,a=0;
            else if(A-a<b) b-=A-a,a=A;
            else a+=b,b=0;
        }
        if(a<mn&&a){mn=a;ans=cnt;}
        if(b<mn&&b){mn=b;ans=cnt;}
        if(c<mn&&c){mn=c;ans=cnt;}
    }
    st.clear();cnt=0;
    a=0,b=0,c=C;
    swap(A,B);
    while(st.find(hsh({a,b}))==st.end()){
        st.insert(hsh({a,b}));
        cnt++;
        if(b==0){
            if(c<B) b=c,c=0;
            else c-=B,b=B;
        }else if(b!=0){
            if(a==A) c+=a,a=0;
            else if(A-a<b) b-=A-a,a=A;
            else a+=b,b=0;
        }
        if(a<mn2&&a){mn2=a;ans2=cnt;}
        if(b<mn2&&b){mn2=b;ans2=cnt;}
        if(c<mn2&&c){mn2=c;ans2=cnt;}
    }
    cout<<min(mn,mn2)<<"\n"<<min(ans,ans2);
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