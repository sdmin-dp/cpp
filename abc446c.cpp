#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define el '\n'
struct Batch {
    int day;
    int count;
};
void solve(){
    int N, D;
    scanf("%d %d", &N, &D);
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < N; i++) scanf("%d", &B[i]);
    deque<Batch> q;
    for (int i = 0; i < N; i++) {
        int cur_day = i + 1;
        q.push_back({cur_day, A[i]});
        int rem = B[i];
        while (rem > 0) {
            if (q.front().count <= rem) {
                rem -= q.front().count;
                q.pop_front();
            } else {
                q.front().count -= rem;
                rem = 0;
            }
        }
        int discard_day = cur_day - D;
        while (!q.empty() && q.front().day <= discard_day) {
            q.pop_front();
        }
    }

    long long ans = 0;
    for (auto &batch : q) ans += batch.count;
    printf("%lld\n", ans);
}
int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}