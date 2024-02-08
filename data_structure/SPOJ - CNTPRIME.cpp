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
 
const int N = 2e5 + 5, MOD = 99971;
int seg[4 * N], lazy[4 * N];
void push_down(int id, int s, int e){
	if (lazy[id]){
		seg[id] = (e - s + 1)* (lazy[id] == 2);
		if (s != e){
			int ch1 = 2 * id, ch2 = ch1 + 1;
			lazy[ch1] = lazy[ch2] = lazy[id];
		}
	}
	lazy[id] = 0;
}
void update(int id, int s, int e, int l, int r, int val){
	push_down(id, s, e);
	if (s > r || e < l)return;
	if (s >= l&&e <= r){
		lazy[id] = val;
		push_down(id, s, e);
		return;
	}
	int mid = s + (e - s) / 2;
	int ch1 = 2 * id, ch2 = ch1 + 1;
	update(ch1, s, mid, l, r, val);
	update(ch2, mid + 1, e, l, r, val);
	seg[id] = seg[ch1] + seg[ch2];
}
int query(int id, int s, int e, int l, int r){
	push_down(id, s, e);
	if (s > r || e < l)return 0;//invalid choise
	if (s >= l&&e <= r)return seg[id];
	int mid = s + (e - s) / 2; 
	int ch1 = 2 * id, ch2 = ch1 + 1;
	return query(ch1, s, mid, l, r) + query(ch2, mid + 1, e, l, r);
}
bool isPrim(int n){
	if (n == 1)return 0;
	for (int i = 2; i*i <= n; i++)
	if (n%i == 0)return 0;
	return 1;
}
int main()
{
	/***  Ø¨Ø³Ù� Ø§Ù�Ù�Ù� Ø§Ù�Ø±Ø­Ù�Ù� Ø§Ù�Ø±Ø­Ù�Ù�   ***/
	//cout << fixed << setprecision(6);
	file();
	fast();
	int t;
	cin >> t;
	for (int cas = 1; cas <= t; cas++){
		cout << "Case " << cas << ":" << endl;
		memset(seg, 0, sizeof seg);
		memset(lazy, 0, sizeof lazy);
		int n, q;
		cin >> n >> q;
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			update(1, 1, n, i, i, isPrim(x)+1);
		}
		while (q--){
			int x, l, r;
			cin >> x >> l >> r;
			if (x)cout <<query(1, 1, n, l, r) << endl;
			else {
				cin >> x;
				update(1, 1, n, l, r, isPrim(x) + 1);
			}
		}
	}
}