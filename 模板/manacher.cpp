/*
 * Manacher算法（马拉车算法）
 * 
 * 算法功能：
 * 在O(n)时间内找出字符串中的最长回文子串
 * 
 * 时间复杂度: O(n)，利用回文对称性避免重复比较
 * 空间复杂度: O(n)
 * 
 * 核心思想：
 * 1. 预处理：在字符间插入特殊字符'#'，使所有回文子串长度都变为奇数
 * 2. 维护最右回文边界：记录当前找到的最右回文子串的中心m和右边界r
 * 3. 利用对称性：对于新位置i，其对称点k=2*m-i，利用p[k]快速初始化p[i]
 * 4. 暴力扩展：从初始半径开始，继续向外扩展
 */

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;

string s;  // 原始字符串
string t;  // 预处理后的字符串（字符间插入'#'）

/**
 * Manacher算法主函数
 * return 最长回文子串
 */
string manacher(){
    if(s.empty()) return "";
    
    // 预处理：在字符间插入'#'，使所有回文子串长度变为奇数
    // 例如 "aba" -> "#a#b#a#"
    t='#';
    for(char c:s) t+=c, t+='#';
    
    ll m=0, r=0, n=t.size();      // m: 当前最右回文串的中心，r: 最右边界
    ll maxlen=0, maxcenter=0;     // maxlen: 最长回文半径，maxcenter: 对应中心点
    vector<ll> p(n, 0);           // p[i]: 以位置i为中心的回文半径（不含中心）
    
    for(int i=0;i<n;i++){
        ll k=2*m-i;  // i关于m的对称点
        
        // 利用对称性快速计算初始半径
        if(i<r){
            // i在当前最右回文边界内
            // 根据对称性，p[i]至少为p[k]，但不能超过r-i
            p[i]=min(r-i, p[k]);
        }
        
        // 暴力扩展：从当前半径开始，继续向外匹配
        int left=i-(1+p[i]), right=i+(1+p[i]);
        while(left>=0 && right<n && t[left]==t[right]){
            p[i]++;
            left--;
            right++;
        }
        
        // 更新最右回文边界
        if(i+p[i]>r){
            m=i;          // 更新中心点
            r=i+p[i];     // 更新右边界
        }
        
        // 记录最长回文子串信息
        if(p[i]>maxlen){
            maxlen=p[i];
            maxcenter=i;
        }
    }
    
    // 从预处理后的字符串位置还原到原始字符串
    // 原始字符串起始位置 = (maxcenter - maxlen) / 2
    ll b=(maxcenter-maxlen)/2;
    return s.substr(b, maxlen);
}

void solve(){
    cin>>s;
    cout<<manacher();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}