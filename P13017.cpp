
using namespace std;

int n, m, a[100005];
long long ans;
int main() {
	cin>>n>>m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin>>u>>v;
		a[u]++;
		a[v]++;
	}
	for (int i = 1; i <= n; i++)
	    ans += (long long)a[i] * (a[i] - 1) / 2;
	printf("%lld", ans);
	return 0;
}
