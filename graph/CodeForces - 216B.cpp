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
int m, n;
vector< vector<int> >adj;
vector<int> vis;
int sum = 0;
void dfs(int ind, int last, int num, int par){
	//cout << ind+1 << " " << last +1<< " " << num << endl;
	if (vis[ind] == 1)
	{
		//cout << num << endl;
		if (adj[ind].size() == 2 && num % 2&&ind ==par)
			sum++;
		return;
	}
	vis[ind] = 1;
	lp(i, adj[ind].size())
	if (adj[ind][i] != last)
		return dfs(adj[ind][i], ind, num + 1,par);
}
int main()
{
	fast();
	cin >> n >> m;
	adj = vector< vector<int> >(n);
	vis = vector<int>(n, 0);
	lp(i, m)
	{
		int a, s;
		cin >> a >> s;
		a--;
		s--;
		adj[a].push_back(s);
		adj[s].push_back(a);
	}
	lp(i, n)
	if (vis[i] == 0){
		dfs(i, i, 0,i);
	}
	if ((n - sum) % 2)
		cout << sum + 1;
	else
		cout << sum;
	//	system("pause");
	return 0;
}