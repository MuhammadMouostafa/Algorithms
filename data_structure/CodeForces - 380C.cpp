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
typedef pair<int, int> pii;
typedef pair<int, pii> node;
const int N = 4000200;
int t[N], o[N], c[N];
string arr;
void build(int id, int s, int e){
	if (s == e){
		if (arr[s - 1] == '(')o[id] = 1;
		else c[id] = 1;
		return;
	}
	int mid = s + (e - s) / 2;
	int ch1 = 2 * id, ch2 = ch1 + 1;
	build(ch1, s, mid);
	build(ch2, mid + 1, e);
	int mn = min(o[ch1], c[ch2]);
	t[id] = t[ch1] + t[ch2] + mn;
	o[id] = o[ch1] + o[ch2] - mn;
	c[id] = c[ch1] + c[ch2] - mn;
}
node query(int id, int s, int e, int l, int r){
	if (s > r || e < l)return node(0, pii(0, 0));//invalid choise3
	if (s >= l&&e <= r)return node(t[id], pii(o[id], c[id]));
	int mid = s + (e - s) / 2;
	int ch1 = 2 * id, ch2 = ch1 + 1;
	node a = query(ch1, s, mid, l, r);
	node b = query(ch2, mid + 1, e, l, r);
	int mn = min(a.second.first, b.second.second);
	int _t = a.first + b.first + mn;
	int _o = a.second.first + b.second.first - mn;
	int _c = a.second.second + b.second.second - mn;
	return node(_t, pii(_o, _c));
}
int main()
{
	/***  بسم الله الرحمن الرحيم   ***/
	//cout << fixed << setprecision(6);
	file();
	fast();
	cin >> arr;
	build(1, 1, arr.size());
	int q;
	cin >> q;
	while (q--){
		int l, r;
		cin >> l >> r;
		cout << 2 * query(1, 1, arr.size(), l, r).first << endl;
	}
}