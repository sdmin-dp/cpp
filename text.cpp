#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
string cmp,s;
ll mp[30];
ll mp2[30];
ll cnt[30];
void solve(){
    cin>>cmp>>s;
    for(size_t i=0;i<cmp.size();i++){
        mp[cmp[i]-'a']=i;
        mp2[i]=cmp[i]-'a';
    }
    for(size_t i=0;i<s.size();i++){
        cnt[mp[s[i]-'a']]++;
    }
    for(int i=0;i<=25;i++){
        // cerr<<cnt[i]<<" ";
        if(cnt[i]==0) continue;
        for(int j=1;j<=cnt[i];j++) printf("%c",mp2[i]+'a');
        // cerr<<mp2[i];
    }
}
int main(){
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
