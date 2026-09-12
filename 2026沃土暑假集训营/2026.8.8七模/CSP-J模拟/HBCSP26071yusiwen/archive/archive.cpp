#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
string s;
multiset<char> st;
unordered_set<char> st2;
void solve(){
    cin>>n;
    cin>>s;
    for(auto &i:s){
        if('a'<=i&&i<='z'){
            st.insert(i);
            st2.insert(i);
        }
        else if('A'<=i&&i<='Z'){
            st.insert(char(i-'A'+'a'));
            st2.insert(char(i-'A'+'a'));
        }
    }
    if(st.empty()){
        cout<<"EMPTY\n0";
        return;
    }
    for(auto i:st) cout<<i;
    cout<<el;
    cout<<st2.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("archive.in","r",stdin);
    freopen("archive.out","w",stdout);
    //freopen("/home/ubuntu/Desktop/HBCSP26071/big/第一题/archive.in","r",stdin);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}