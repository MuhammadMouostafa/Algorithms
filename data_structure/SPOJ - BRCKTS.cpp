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
void stop(){
#ifndef ONLINE_JUDGE
	system("pause");
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
int setbit(int num, int idx, int val = 1){ return (val) ? (num | (1 << idx)) : (num&~(1 << idx)); }
int getbit(int num, int idx){ return ((num >> idx) & 1) == 1; }
int contbit(int num){ int ret = 0; while (num){ if (num % 2)ret++; num /= 2; }return ret; }
struct word{
	int l, r;
};
word combin(word l, word r){
	word w;
	w.l = l.l + r.l - min(l.l, r.r);
	w.r = l.r + r.r - min(l.l, r.r);
	return w;
}
const int MAXN = 30000;
int n;
word t[4 * MAXN];
string a;
void build( int v, int tl, int tr) {
	if (tl == tr){
		if (a[tl] == '(')
			t[v].l = 1, t[v].r = 0;
		else t[v].l = 0, t[v].r = 1;
	}
	else {
		int tm = (tl + tr) / 2;
		build( v * 2, tl, tm);
		build( v * 2 + 1, tm + 1, tr);
		word l = t[v * 2];
		word r = t[v * 2 + 1];
		t[v] = combin(l,r);
	}
}
void update(int v, int tl, int tr, int pos) {
	if (tl == tr){
		if (a[tl] == '(')
			t[v].l = 1, t[v].r = 0;
		else t[v].l = 0, t[v].r = 1;
	}
	else {
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			update(v * 2, tl, tm, pos);
		else
			update(v * 2 + 1, tm + 1, tr, pos);
		word l = t[v * 2];
		word r = t[v * 2 + 1];
		t[v] = combin(l, r);
	}
}
int main(){
	fast();
	int k = 1;
	while (cin >> n){
		cin >> a;
		build(1, 0, n - 1);
		int m;
		cin >> m;
		cout << "Test " << k++ << ":" << endl;
		while (m--){
			int l;
			cin >> l;
			if (!l){
					if (t[1].l==0&&t[1].r==0)
						cout << "YES" << endl;
					else cout << "NO" << endl;
			}
			else {
				l--;
				if (a[l] == '(')
					a[l] = ')';
				else a[l] = '(';
				update(1, 0, n - 1, l);
			}
		}
	}
	stop();
	return 0;
} 