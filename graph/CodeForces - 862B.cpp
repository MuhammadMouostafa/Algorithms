// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <deque>


#define  all(v)         ((v).begine()),((v).end())
#define  sz(v)	        ((int)(v).size())
#define	 clr(v,d)       memset(v,d,sizeof(v))
#define  lp(i,n)        for(int i=0; i<n; i++)
#define  lpi(i,j,n)     for(int i=j; i<n; i++)
#define  lpd(i,j,n)     for(int i=j; i>=n; i--)
const double E = 1e-12;

typedef  long long ll;
typedef  long double ld;
/*typedef  vector<int> vi;
typedef  vector<char> vc;
typedef  vector<string> vs;
typedef  vector<bool> vb();
*/
using namespace std;

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}

int main()
{
	fast();
	int n;
	cin >> n;
	vector< vector<int> >edj(n);
	lp(i, n - 1)
	{
		int from, to;
		cin >> from >> to;
		from--;
		to--;
		edj[from].push_back(to);
		edj[to].push_back(from);
	}
	vector<int> vis(n,-1);
	unsigned long long a[2] = { 0 };
	queue<int> q;
	q.push(0);
	int dep = 1,sz=1;
	for (; !q.empty(); dep++, sz = q.size()){
		while (sz--){
			int cur = q.front();
			q.pop();
			lp(i, edj[cur].size()){
				int child = edj[cur][i];
				if (vis[child] == -1){
					vis[child] = dep;
					q.push(child);
					a[dep%2]++;
				}
			}
		}
	}
	cout << a[0] * a[1] - n + 1;
	return 0;
}