#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 2e2 + 10;

int n, idx = 0;
string s, t, ss, ans;
char in[N];
vector<char> G[N];
set<char> st;

void topu () {
    queue<char> q;
    for (char i = 'a'; i <= 'z'; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty ()) {
        if (q.size () > 1) {
            cout << 0;
            exit (0);
        }
        auto v = q.front();
        q.pop();
        ans.push_back(v);
        for (auto x :G[v]) {
            if (--in[x] == 0) {
                q.push (x);
            }
        }
    }
}

void solve() {
    cin >> n;
    cin >> s;
    memset(in, -1, sizeof in);
    for (int i = 2; i <= n; i++) {
        cin >> t;
        int len = max(s.size(), t.size());
        for (int j = 0; j < len; j++) {
            if (s[j] != t[j]) {
                if (s.size () < j && t.size () >= j)
                    continue;
                else if (t.size () < j && s.size () >= j) {
                    cout << 0;
                    return;
                } else {
                    auto u = s[j], v = t[j];
                    G[u].push_back(v);
                    if (in[u] == -1)
                        in[u] = 0;
                    if (in[v] == -1)
                        in[v] = 0;
                    in[v]++;
                    break;
                }
            }
        }
        s = t;
    }
    cin >> ss;
    topu();

    map<int, int> mp;
    string ttt = ans;
    string ans_ans = "";
    sort(ttt.begin(), ttt.end());
    for (int i = 0; i < ans.size(); i++)
        mp[ans[i]] = ttt[i];
    for (int i = 0; i < ss.size(); i++) {
        if (mp.find (ss[i]) == mp.end ()) {
            cout << 0;
            return;
        }
        ans_ans.push_back(mp[ss[i]]);
    }
    cout << ans_ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(0);

    int T = 1; // cin >> T;
    while (T--)
        solve();

    return 0;
}