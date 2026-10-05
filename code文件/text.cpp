#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
string s;
vector<string> v;

bool f (char c) {
    return (c == ',' || c == '.' || c  == ';' || c == ':' || c == '!' || c == '?' || c == ' ');
}

bool shuzi (string s) {
    if (s.empty ())
            return false;
    bool fl = true;
    for (auto c : s) {
        if (c >= '0' && c <= '9') {
            continue;
        } else {
            fl = false;
            break;
        }
    }
    return fl;
}

bool shuzi2 (string s) {
    bool fl = false;
    for (auto c : s) {
        if (c >= '0' && c <= '9') {
            fl = true;
            break;
        }
    }
    return fl;
}

void solve () {
    string t = "";
    getline (cin, s);
    v.clear ();
    s = '.' + s + '.';
    for (int i = 0; i < s.size () - 1; i++) {
        if (f (s[i]))
            continue;
        else {
            if (f (s[i + 1])) {
                t = t + s[i];
                v.push_back (t);
                t = "";
            } else {
                t = t + s[i];
            }
        }
    }

    string mxlen = "";
    ll cnt1 = 0, cnt2 = 0;
    for (auto i : v) {
        if (shuzi (i))
            cnt1++;
        if (shuzi2 (i))
            cnt2++;
        mxlen = (i.size () > mxlen.size () ? i : mxlen);
    }

    cout << v.size () << '\n';
    cout << mxlen << '\n';
    cout << cnt1 << " " << cnt2 << '\n';
}

int main () {
    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);

    freopen ("station.in", "r", stdin);
    freopen ("station.out", "w", stdout);

    int T = 1;
    cin >> T;
    string sdfv;
    getline(cin,sdfv);
    while (T--)
        solve ();

    return 0;
}