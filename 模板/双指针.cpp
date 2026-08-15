#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

ll n,k;
ll a[N];

// 1. 快慢指针：原地去重（返回去重后的长度）
ll fast_slow(){
    if(n==0) return 0;
    ll slow=1; // 慢指针：指向当前无重复元素的末尾
    for(int fast=2;fast<=n;fast++){ // 快指针：向前探路
        if(a[fast]!=a[slow]){
            a[++slow]=a[fast]; // 找到新元素，慢指针前移并覆盖
        }
    }
    return slow;
}

// 2. 对撞指针：找两数之和等于 k 的位置
void opposite(){
    ll l=1,r=n;
    while(l<r){
        ll sum=a[l]+a[r];
        if(sum==k){
            cout<<l<<" "<<r<<el;
            return;
        }
        if(sum<k) l++;
        else r--;
    }
    cout<<-1<<el;
}

// 3. 滑动窗口（遍历 L 扩大 R）：求区间和 <= k 的最长子数组长度
void slide_L_expand_R(){
    ll r=1,sum=0,ans=0;
    for(int l=1;l<=n;l++){
        while(r<=n && sum+a[r]<=k){ // 只要加上下一个不过界，R 就一直右移
            sum+=a[r];
            r++;
        }
        ans=max(ans,r-l); // 此时合法区间为 [l, r-1]
        sum-=a[l]; // L 即将右移，吐出 a[l]
    }
    cout<<ans<<el;
}

// 4. 滑动窗口（遍历 R 收缩 L）：求区间和 <= k 的最长子数组长度
void slide_R_shrink_L(){
    ll l=1,sum=0,ans=0;
    for(int r=1;r<=n;r++){
        sum+=a[r]; // 吃进右边界 a[r]
        while(l<=r && sum>k){ // 不合法时，L 循环右移吐数据
            sum-=a[l];
            l++;
        }
        ans=max(ans,r-l+1); // 此时合法区间为 [l, r]
    }
    cout<<ans<<el;
}

void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];

    // 按需调用即可：
    // cout<<fast_slow()<<el;
    // opposite();
    // slide_L_expand_R();
    // slide_R_shrink_L();
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