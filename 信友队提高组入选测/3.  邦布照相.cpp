#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const int N=2e5+5;
int n,k,a[N],cnt[N],stk[N],top;
bool vis[N];
void solve(){
    if(!(cin>>n>>k))return;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        cnt[a[i]]--;
        if(vis[a[i]])continue; 
        while(top>0&&a[i]<stk[top]&&cnt[stk[top]]>0){
            vis[stk[top]]=0;
            top--;
        }
        stk[++top]=a[i];
        vis[a[i]]=1;
    }
    for(int i=1;i<=top;i++)cout<<stk[i]<<(i==top?"":" ");
    cout<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("photo.in","r",stdin);
    freopen("photo.out","w",stdout);
    solve();
    return 0;
}
