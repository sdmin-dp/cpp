#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s,t;
stringstream ss;
stack<string> st;
unordered_map<string,ll> mp={{"(",0},{"+",1},{"-",1},{"*",2},{"/",2},{"^",3}};
bool isoperator(string p){
    return (p=="+"||p=="-"||p=="*"||p=="/"||p=="^"||p=="%");
}
vector<string> res;
void solve(){
    getline(cin,s);
    bool flag=1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='-'&&flag){
            t.push_back(s[i]);
            flag=0;
        }else if(!(s[i]>='0'&&s[i]<='9')){
            t.push_back(' ');
            t.push_back(s[i]);
            t.push_back(' ');
            flag=(s[i]!=')');
        }else{
            t.push_back(s[i]);
            flag=0;
        }
    }
    ss<<t;
    while(ss>>s){
        if(s=="(") st.push(s);
        else if(isoperator(s)){
            while(!st.empty()&&mp[st.top()]>=mp[s]){
                res.push_back(st.top());st.pop();
            }
            st.push(s);
        }else if(s==")"){
            while(st.top()!="("){
                res.push_back(st.top());st.pop();
            }
            st.pop();
        }
        else{
            res.push_back(s);
        }
    }
    while(!st.empty()){
        res.push_back(st.top());st.pop();
    }
    stringstream sss;
    string ssss;
    for(int i=0;i<res.size();i++) ssss+=res[i]+' ';
    cout<<ssss;
    // sss<<ssss;
    // stack<char> stk;
    // while(sss>>s){
    //     ll x=0;
    //     if(s.size()==1&&!(s[0]>='1'&&s[0]<='9')){
    //         ll a=stk.top();stk.pop();
    //         ll b=stk.top();stk.pop();
    //         if(s=="+") stk.push(a+b);
    //         if(s=="-") stk.push(a-b);
    //         if(s=="*") stk.push(a*b);
    //         if(s=="/") stk.push(a/b);
    //         if(s=="%") stk.push(b%a);
    //     }
    //     else{
    //         x=stoll(s);
    //         stk.push(x);
    //     }
    // }
    // cout<<stk.top();
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}