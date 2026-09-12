#include <bits/stdc++.h>
#include "treasure.h"
using namespace std;
int ax,ay,c,cnt;
void WA() {
	puts("Wrong Answer.");
	exit(0);
}
int query(int x,int y) {
	if (abs(x)>1e9||abs(y)>1e9) WA();
	if (++cnt>c) WA();
	return abs(x-ax)+abs(y-ay);
}
int main() {
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	cin>>ax>>ay>>c;
	int xx=-1,yy=-1;
	treasure(c,xx,yy);
	if (xx!=ax||yy!=ay) WA();
	printf("AC with %d query(s).",cnt);
}