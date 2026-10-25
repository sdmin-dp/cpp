#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
map<string,ll> mp={
    {"zero",0},
    {"one",1},
    {"two",2},
    {"three",3},
    {"four",4},
    {"five",5},
    {"six",6},
    {"seven",7},
    {"eight",8},
    {"nine",9},
    {"ten",10},
    {"eleven",11},
    {"twelve",12},
    {"thirteen",13},
    {"fourteen",14},
    {"fifteen",15},
    {"sixteen",16},
    {"seventeen",17},
    {"eighteen",18},
    {"nineteen",19},
    {"twenty",20},
    {"a",1},
    {"both",2},
    {"another",1},
    {"third",3},
    {"second",2},
    {"first",1}
};
void solve(){
    string s,ans;
    vector<string> v;
    getline(cin,s);
    stringstream ss;
    ss<<s;
    while(ss>>s){
        if(s=="zero"||mp[s]!=0){
            ll x=mp[s]*mp[s];
            string t=to_string(x);
            x%=100;
            if(t.size()==1){
                char c=t[0];
                t.clear();
                t.push_back('0');
                t.push_back(c);
            }
            v.push_back(t);
        }
    }
    sort(v.begin(),v.end());
    for(auto &t:v){
        ans.push_back(t[0]);
        ans.push_back(t[1]);
    }
    reverse(ans.begin(),ans.end());
    while(ans[ans.size()-1]=='0'&&ans.size()>1){
        // cerr<<ans<<" ";
        ans.pop_back();
        // cerr<<ans<<el;
    }
    reverse(ans.begin(),ans.end());
    if(ans.size()==0) ans.push_back('0');
    cout<<ans;
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