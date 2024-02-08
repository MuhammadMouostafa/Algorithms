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
 
 
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
 
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int dx[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
char dir[] = { 'U', 'R', 'D', 'L' };
 
//328,990
//?1000,2
 
const int N = 1e6 + 5, MOD = 99971;
int seg[4 * N];
void build(int id, int s, int e){
	if (s == e){
		seg[id] = 1;
		return;
	}
	int mid = s + (e - s) / 2;
	int ch1 = 2 * id, ch2 = ch1 + 1;
	build(ch1, s, mid);
	build(ch2, mid + 1, e);
	seg[id] = seg[ch1] + seg[ch2];
}
void update(int id, int s, int e, int pos){
	if (s == e){
		seg[id] = 0;
		return;
	}
	int mid = s + (e - s) / 2;
	int ch1 = 2 * id, ch2 = ch1 + 1;
	if (pos <= mid) update(ch1, s, mid, pos);
	else update(ch2, mid + 1, e, pos);
	seg[id] = seg[ch1] + seg[ch2];
}
int query(int id, int s, int e, int l, int r){
	if (s > r || e < l)return 0;//invalid choise3
	if (s >= l&&e <= r)return seg[id];
	int mid = s + (e - s) / 2;
	int ch1 = 2 * id, ch2 = ch1 + 1;
	return query(ch1, s, mid, l, r) + query(ch2, mid + 1, e, l, r);
}
int main()
{
	/***  Ø¨Ø³Ù� Ø§Ù�Ù�Ù� Ø§Ù�Ø±Ø­Ù�Ù� Ø§Ù�Ø±Ø­Ù�Ù�   ***/
	//cout << fixed << setprecision(6);
	file();
	fast();
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(all(v));
	build(1, 1, n);
	int q;
	cin >> q;
	vector<vector<int>> a(q, vector<int>(4));
	for (int i = 0; i < q; i++){
		cin >> a[i][1] >> a[i][2] >> a[i][0];
		a[i][3] = i;
	}
	sort(all(a));
	vector<int> ans(q);
	int pos = 0;
	for (auto i : a){
		while (pos < n&&v[pos].first <= i[0]){
			update(1, 1, n, v[pos++].second+1);
		}
		ans[i[3]] = query(1, 1, n, i[1], i[2]);
	}
	for (int i : ans)cout << i << endl;
}