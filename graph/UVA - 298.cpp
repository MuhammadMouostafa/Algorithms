#define _CRT_SECURE_NO_WARNINGS
#ifdef __GNUC__
# define ffs(x) __builtin_ffs(x)
#elif __INTEL_COMPILER
# define ffs(x) _bit_scan_forward(x)
#endif
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename key>
using ordered_set = tree<key, null_type, less<key>, rb_tree_tag, tree_order_statistics_node_update>;



using ll = long long;
#define all(v) v.begin(),v.end()
#define EPS 1e-10
#define INF 1e18
#define PI acos(-1.0)
#define sz(s)    (int)(s.size())
#define endl "\n"
void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
}
void fast()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

template<class val>
istream& operator>>(istream& is, vector<val>& vec) {
    for (int i = 0; i < vec.size(); i++)
        is >> vec[i];
    return is;
}
template<class val>
ostream& operator<<(ostream& os, vector<val>& vec) {
    for (int i = 0; i < sz(vec); i++) {
        os << vec[i];
        if (i + 1 < sz(vec))
            os << ' ';
    }
    return os;
}
template<class f, class s>
istream& operator>>(istream& is, pair<f, s>& p) {
    is >> p.first >> p.second;
    return is;
}
template<class f, class s>
ostream& operator<<(ostream& os, pair<f, s>& p) {
    os << "{" << p.first << ',' << p.second << "}";
    return os;
}

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
char dir[] = {'U', 'R', 'D', 'L'};

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int n,m;
vector<vector<bool>> g;
bool valid(int i, int j, int x, int y){
    return i>=0&&j>=0&&i<n&&j<m&&g[i][j]&&x>=-3&&y>=-3&&x<=3&&y<=3;
}
void Main(const int &T){
    cin>>n>>m;
    g=vector<vector<bool>>(n,vector<bool>(m,1));
    int xs,ys,xe,ye;
    cin>>xs>>ys>>xe>>ye;
    int p;
    cin>>p;
    while(p--){
        int x1,y1,x2,y2;
        cin>>x1>>x2>>y1>>y2;
        for(int i=x1; i<=x2; i++){
            for(int j=y1; j<=y2; j++){
                g[i][j]=0;
            }
        }
    }
    map<vector<int>,int> dis;
    queue<vector<int>> q;
    dis[{xs,ys,0,0}]=0;
    q.push({xs,ys,0,0});
    while(!q.empty()){
        auto cur=q.front();
        if(cur[0]==xe&&cur[1]==ye){
            cout<<"Optimal solution takes "<< dis[cur] <<" hops."<<endl;
            return;
        }
        q.pop();
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                auto nxt=cur;
                nxt[2]+=i;
                nxt[3]+=j;
                nxt[0]+=nxt[2];
                nxt[1]+=nxt[3];
                if(valid(nxt[0],nxt[1],nxt[2],nxt[3]) &&(dis.find(nxt)==dis.end()||dis[nxt]>dis[cur]+1)){
                    dis[nxt] = dis[cur]+1;
                    q.push(nxt);
                }  
            }
        }
    }

    cout<<"No solution."<<endl;
}
int main()
{
    file();
    fast();
    int T = 1;
    cin>>T;
    for(int t=1; t<=T; t++){
        // cout<<"Case "<< t <<": ";
        Main(t);
    }
}