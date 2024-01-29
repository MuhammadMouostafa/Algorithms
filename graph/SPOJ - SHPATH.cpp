#define __popcnt __builtin_popcount
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define	 clr(v,d)       memset(v,d,sizeof(v))
#define  lp(i,n)        for(int i=0; i<n; i++)
#define  rep(i,v)       for(int i=0; i<(int)v.size(); i++)
#define cini(n)         scanf("%d",&n)
#define cinl(n)         scanf("%lld",&n)
#define cind(n)         scanf("%Lf",&n)
#define cinf(n)         scanf("%f",&n)   
#define cinc(n)         scanf("%c",&n)
#define cins(n)         scanf("%s",&n)
#define cinsl(n)        cin.ignore(), scanf("%[^\n]%*c",n)
#define couti(n)         printf("%d",n)
#define coutl(n)         printf("%lld",n)
#define coutd(n)         printf("%Lf",n)
#define coutdd(n)         printf("%.9l f",n)
#define coutf(n)         printf("%f",n)   
#define coutc(n)         printf("%c",n)
#define coutarc(n)         printf("%s",n)
#define couts(n)         printf("%s",n.c_str())
#define coutln()         printf("\n")   
#define coutsp(n)         printf(" ")

typedef  long long ll;
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
#endif
}
int dx[] = { 0,   0, -1,  1 , 1 ,  1 , -1 , -1 };
int dy[] = { 1, - 1,  0,  0 , 1 , -1 ,  1 , -1 };
struct edge{
	ll from, to, w;
	edge(int from,int to, int w) :from(from),to(to),w(w){}
	bool operator < (const edge & e)const{
		return w>e.w;
	}
};
int main(){
	fast();
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n;
		vector< vector<edge> > adj(n, vector<edge>());
		map<string, int> mp;
		lp(i, n){
			string s;
			cin >> s;
			mp[s] = i;
			cin >> m;
			while (m--){
				int to, w;
				cin >> to >> w; to--;
				adj[i].push_back({ i, to, w });
			}
		}
		cin >> m;
		while (m--){
			string a1, a2;
			cin >> a1 >> a2;
			int s, d;
			s = mp[a1];
			d = mp[a2];
			vector<ll> len(n, 1e18);
			len[s] = 0;
			priority_queue<edge> q;
			q.push({ -1, s, 0 });
			while (!q.empty()){
				edge e = q.top(); q.pop();
				if (len[e.to] < e.w)continue;
				rep(i, adj[e.to]){
					edge ne = adj[e.to][i];
					if (len[ne.to]>len[ne.from] + ne.w){
						ne.w = len[ne.to] = len[ne.from] + ne.w;
						q.push(ne);
					}
				}
			}
			if (len[d] == 1e18)
				cout << -1 << endl;
			else
				cout << len[d] << endl;
		}
	}
	
	stop();
	return 0;
}
