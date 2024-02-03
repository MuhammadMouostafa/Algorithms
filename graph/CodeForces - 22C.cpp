#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void file(){
#ifndef ONLINE_JUDGE
	freopen("a_input.txt", "r", stdin);
	freopen("a_output.txt", "w", stdout);
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
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int main(){
	/* بسم الله توكلت علي الله */
	file();
	fast();
	ll n, m, v;
	cin >> n >> m >> v;
	vector<int> a(n);
	for (int i = 1; i <= n; i++)
		a[i-1] = i;
	if (a[n - 1] == v)
		swap(a[n - 1], a[n - 2]);
	int u = a.back();
	a.pop_back();
	n--;
	if ((n*(n - 1)) / 2 < m - 1 || m < n){
		cout << -1;
		return 0;
	}
	m-=n;
	cout << v << " " << u << "\n";
	for (int i = 0; i < n - 1; i++)
		cout << a[i] << " " << a[i + 1] << "\n";
	for (int i = 0; i + 2 < n&&m; i++){
		int j = i + 2;
		while (m&&j < n){
			m--;
			cout << a[i] << " " << a[j++] << "\n";
		}
	}
}