//#define __popcnt __builtin_popcount
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define sz(a) ((int)(a).size())
#define all(n) (n).begin(),(n).end()
#define clr(v,val) memset(v , val , sizeof v)
#define EPS 1e-6
#define OO 1e9
#define PI acos(-1.0)
#define ll long long
#define endl "\n"
 
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
}
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
 
 
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int dx[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
char dir[] = { 'U', 'R', 'D', 'L' };
typedef pair<int, int> pi;
typedef pair<pi, pi> pii;
//472,440
//7000
 
const int N = 5e4 + 5, mod = 1e9 + 7;
struct node{
	int sm, mx, mxl, mxr;
	node(){};
	node(int sm, int mx, int mxl, int mxr) :sm(sm), mx(mx), mxl(mxl), mxr(mxr){};
};
node compine(node a,node b){
	node c;
	c.sm = a.sm + b.sm;
	c.mxl = max({ a.mxl, a.sm + b.mxl, c.sm });
	c.mxr = max({ b.mxr, b.sm + a.mxr, c.sm });
	c.mx = max({ a.mx, b.mx, c.sm, c.mxl, c.mxr, b.mxl + a.mxr });
	return c;
}
int arr[N];
node seg[4 * N];
void build(int id, int s, int e){
	if (s == e){
		seg[id].mx = seg[id].mxl = seg[id].mxr = seg[id].sm = arr[s];
		return;
	}
	int mid = s + (e - s) / 2;
	int ch1 = 2 * id, ch2 = ch1 + 1;
	build(ch1, s, mid);
	build(ch2, mid + 1, e);
	seg[id] = compine(seg[ch1], seg[ch2]);
}
void update(int id, int s, int e, int pos, int val){
	if (s == e){
		seg[id].mx = seg[id].mxl = seg[id].mxr = seg[id].sm = val;
		return;
	}
	int mid = s + (e - s) / 2;
	int ch1 = 2 * id, ch2 = ch1 + 1;
	if (pos <= mid) update(ch1, s, mid, pos, val);
	else update(ch2, mid + 1, e, pos, val);
	seg[id] = compine(seg[ch1], seg[ch2]);
}
node query(int id, int s, int e, int l, int r){
	if (s > r || e < l)return node(0, -1e9, -1e9, -1e9);//invalid choise
	if (s >= l&&e <= r)return seg[id];
	int mid = s + (e - s) / 2;
	int ch1 = 2 * id, ch2 = ch1 + 1;
	node res1 = query(ch1, s, mid, l, r);
	node res2 = query(ch2, mid + 1, e, l, r);
	return compine(res1, res2);
}
int main()
{
	/***  Ø¨Ø³Ù� Ø§Ù�Ù�Ù� Ø§Ù�Ø±Ø­Ù�Ù� Ø§Ù�Ø±Ø­Ù�Ù�   ***/
	file();
	fast();
	int n, q;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	cin >> q;
	while (q--){
		int x, l, r;
		cin >> x >> l >> r;
		if (x){
			cout << query(1, 1, n, l, r).mx;
			if (q)cout << endl;
		}
		else
			update(1, 1, n, l, r);
	}
} 