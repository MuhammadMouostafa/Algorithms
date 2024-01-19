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
ll n, m, x = 1;
vector<string> a;
int v = 0;
string s, o;
ll ind = 0;
void dfs(){
	if (ind >= n){
		x = 0;
		return;
	}
	if (a[ind] == "pair"){
		s += "pair<";
		++ind;
		dfs();
		s += ",";
		++ind;
		dfs();
		s += ">";
	}
	else {
		s += "int";
	}
}
int main()
{
	fast();
	cin >> m;
	n = 0;
	while (cin >> o){
		n++;
		a.push_back(o);

	}
	if (a[0] == "int"){
		if (n == 1)
			cout << "int";
		else cout << "Error occurred";
	}
	else {
		dfs();
		if (x&&ind == n-1)
			cout << s;
		else cout << "Error occurred";
	}
	return 0;
}