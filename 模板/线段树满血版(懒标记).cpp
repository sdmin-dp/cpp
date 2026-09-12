#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;

// 线段树节点结构体
struct segment{
    ll l,r;        // 节点表示的区间范围[l, r]
    ll sum;        // 区间和
    ll tag;        // 懒标记，用于延迟更新
}t[N*4];          // 开4倍空间，确保完全二叉树有足够存储空间

ll n,m;           // n:数组长度, m:操作次数
ll a[N];          // 原始数组

// 向上更新：用子节点信息更新父节点
void pushup(ll idx){
    t[idx].sum = t[idx*2].sum + t[idx*2+1].sum;  // 父节点和 = 左子节点和 + 右子节点和
}

// 建树函数
// l,r: 当前节点表示的区间范围，idx: 当前节点编号
void build(ll l=1, ll r=n, ll idx=1){
    t[idx].l = l;  // 记录节点区间左端点
    t[idx].r = r;  // 记录节点区间右端点
    
    // 到达叶子节点（区间长度为1）
    if(l == r){
        t[idx].sum = a[l];  // 叶子节点直接存储数组元素值
        return;
    }
    
    // 递归构建左右子树
    ll mid = (l + r) / 2;      // 区间中点
    build(l, mid, idx*2);      // 构建左子树[l, mid]
    build(mid+1, r, idx*2+1);  // 构建右子树[mid+1, r]
    
    pushup(idx);  // 向上更新当前节点的区间和
}

// 懒标记下传
void pushdown(ll idx){
    ll l = t[idx].l;
    ll r = t[idx].r;
    ll tag = t[idx].tag;
    
    // 如果是叶子节点或者没有懒标记，直接返回
    if(l == r || tag == 0) return;
    
    // 1. 更新左右儿子的区间和
    // 左儿子区间和增加：标记值 × 左儿子区间长度
    t[idx*2].sum += (t[idx*2].r - t[idx*2].l + 1) * tag;
    // 右儿子区间和增加：标记值 × 右儿子区间长度
    t[idx*2+1].sum += (t[idx*2+1].r - t[idx*2+1].l + 1) * tag;
    
    // 2. 给左右儿子打上懒标记
    t[idx*2].tag += tag;
    t[idx*2+1].tag += tag;
    
    // 3. 清空当前节点的懒标记（已经下传）
    t[idx].tag = 0;
}

// 区间更新函数
// [s,e]: 要更新的区间范围，k: 要增加的值，idx: 当前节点编号
void update(ll s, ll e, ll k, ll idx=1){
    ll l = t[idx].l;
    ll r = t[idx].r;
    
    // 情况1：当前区间完全包含在要更新的区间内
    if(s <= l && r <= e){
        ll len = r - l + 1;  // 区间长度
        t[idx].sum += len * k;  // 直接更新当前区间和
        t[idx].tag += k;       // 打上懒标记（延迟更新子节点）
        return;
    }
    
    // 情况2：当前区间与更新区间部分重叠
    pushdown(idx);  // 先将懒标记下传给子节点
    
    ll mid = (l + r) / 2;
    // 如果更新区间与左儿子有重叠，更新左子树
    if(s <= mid) update(s, e, k, idx*2);
    // 如果更新区间与右儿子有重叠，更新右子树
    if(e > mid) update(s, e, k, idx*2+1);
    
    pushup(idx);  // 更新后向上更新父节点的区间和
}

// 区间查询函数
// [s,e]: 要查询的区间范围，idx: 当前节点编号
ll query(ll s, ll e, ll idx=1){
    ll l = t[idx].l;
    ll r = t[idx].r;
    
    // 情况1：当前区间完全包含在查询区间内，直接返回区间和
    if(s <= l && r <= e) 
        return t[idx].sum;
    
    // 情况2：查询区间与当前区间无交集，返回0
    if(s > r || e < l) 
        return 0;
    
    // 情况3：查询区间与当前区间部分重叠
    pushdown(idx);  // 下传懒标记，确保数据最新
    
    // 分别查询左右子树并求和
    return query(s, e, idx*2) + query(s, e, idx*2+1);
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];  // 读入原始数组
    
    build();  // 构建线段树
    
    while(m--){
        ll op, x, y, k;
        cin >> op;
        if(op == 1){  // 区间更新操作
            cin >> x >> y >> k;
            update(x, y, k);
        }
        else{  // 区间查询操作
            cin >> x >> y;
            cout << query(x, y) << el;  // 输出区间和
        }
    }
}

int main() {
    // 注释掉的代码是常用的输入输出优化和文件操作
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    
    ll T = 1;
    //cin >> T;  // 多组测试数据时使用
    while(T--){
        solve();
    }
    return 0;
}