#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll c[3][3];
int pw[16];

// 暴力：Dijkstra 在 3^n 状态图上求最短路
ll dij(){
    int N=pw[n];
    vector<ll> dist(N, LLONG_MAX);
    int start=0;
    int goal=0;
    for(int d=0; d<n; d++) goal += 2*pw[d];
    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
    dist[start]=0; pq.push(make_pair(0LL,start));
    while(!pq.empty()){
        pair<ll,int> cur=pq.top(); pq.pop();
        ll du=cur.first; int u=cur.second;
        if(du!=dist[u]) continue;
        if(u==goal) return du;
        int tmp=u; int peg[16];
        for(int d=0; d<n; d++){ peg[d]=tmp%3; tmp/=3; }
        int top[3]; top[0]=top[1]=top[2]=-1;
        for(int d=0; d<n; d++) if(top[peg[d]]==-1) top[peg[d]]=d; // 最小号=最上面
        for(int p=0;p<3;p++){
            int disk=top[p];
            if(disk==-1) continue;
            for(int q=0;q<3;q++){
                if(q==p) continue;
                if(top[q]!=-1 && top[q] < disk) continue; // q 顶上有更小的，放不下
                int v = u - p*pw[disk] + q*pw[disk];
                ll nd = du + c[p][q];
                if(nd < dist[v]){ dist[v]=nd; pq.push(make_pair(nd,v)); }
            }
        }
    }
    return dist[goal];
}

// 我的两策略 DP
ll dpf(){
    ll d[3][3];
    for(int i=0;i<3;i++)for(int j=0;j<3;j++) d[i][j]=(i==j?0:c[i][j]);
    for(int k=0;k<3;k++)for(int i=0;i<3;i++)for(int j=0;j<3;j++) d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
    static ll f[64][3][3];
    for(int i=0;i<3;i++)for(int j=0;j<3;j++) f[1][i][j]=d[i][j];
    for(int m=2;m<=n;m++)
        for(int i=0;i<3;i++)for(int j=0;j<3;j++){
            if(i==j){ f[m][i][j]=0; continue; }
            int k=3-i-j;
            ll A=f[m-1][i][k]+c[i][j]+f[m-1][k][j];
            ll B=f[m-1][i][j]+c[i][k]+f[m-1][j][i]+c[k][j]+f[m-1][i][j];
            f[m][i][j]=min(A,B);
        }
    return f[n][0][2];
}

int main(){
    pw[0]=1; for(int i=1;i<16;i++) pw[i]=pw[i-1]*3;
    auto setc=[&](ll x,ll y,ll z){
        c[0][1]=c[1][0]=x; c[1][2]=c[2][1]=y; c[0][2]=c[2][0]=z;
    };
    n=1; setc(1,1,100); printf("sample1 brute=%lld dp=%lld (expect 2)\n", dij(), dpf());
    n=3; setc(1,1,1);   printf("sample2 brute=%lld dp=%lld (expect 7)\n", dij(), dpf());
    n=3; setc(2,3,10);  printf("sample3 brute=%lld dp=%lld (expect 30)\n", dij(), dpf());

    mt19937 rng(12345);
    int cnt=0;
    for(int t=0;t<3000 && cnt<15;t++){
        n = 1 + rng()%8;
        ll x=rng()%30+1, y=rng()%30+1, z=rng()%30+1;
        setc(x,y,z);
        ll b=dij(), dd=dpf();
        if(b!=dd){ printf("MISMATCH n=%d x=%lld y=%lld z=%lld brute=%lld dp=%lld\n",n,x,y,z,b,dd); cnt++; }
    }
    printf("done mismatches(with cap)=%d\n", cnt);
    return 0;
}
