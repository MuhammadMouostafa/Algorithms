#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
struct data {
	int sum, pref, suff, ans;
};
data combine(data l, data r) {
	data res;
	res.sum = l.sum + r.sum;
	res.pref = max(l.pref, l.sum + r.pref);
	res.suff = max(r.suff, r.sum + l.suff);
	res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
	return res;
}
data make_data(int val) {
	data res;
	res.sum = res.pref = res.suff = res.ans = val;
	return res;
}
const int MAXN = 50001;
int n;
data t[4 * MAXN];
void build(int a[], int v, int tl, int tr) {
	if (tl == tr)
		t[v] = make_data(a[tl]);
	else {
		int tm = (tl + tr) / 2;
		build(a, v * 2, tl, tm);
		build(a, v * 2 + 1, tm + 1, tr);
		t[v] = combine(t[v * 2], t[v * 2 + 1]);
	}
}
data query(int v, int tl, int tr, int l, int r) {
	if (l == tl && tr == r)
		return t[v];
	int tm = (tl + tr) / 2;
	if (r <= tm)
		return query(v * 2, tl, tm, l, r);
	if (l > tm)
		return query(v * 2 + 1, tm + 1, tr, l, r);
	return combine(
		query(v * 2, tl, tm, l, tm),
		query(v * 2 + 1, tm + 1, tr, tm + 1, r)
		);
}
int main(){
	scanf("%d", &n);
	int a[MAXN];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	build(a, 1, 0, n - 1);
	int m;
	cin >> m;
	while (m--){
		int l, r;
		cin >> l >> r;
		r--; l--;
		data ans = query(1, 0, n - 1, l, r);
		printf("%d\n", max(max(ans.ans, ans.sum), max(ans.pref, ans.suff)));
	}
	return 0;
} 