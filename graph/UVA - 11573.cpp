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
    // freopen("output.out", "w", stdout);
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

// int dx[] = {-1, 0, 1, 0, 1, 1, -1, -1};
// int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dx[] = {-1,-1,0, 1, 1,1, 0,-1};
int dy[] = {0, 1, 1, 1, 0,-1, -1,-1};

char dir[] = {'U', 'R', 'D', 'L'};

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

struct edge
{
    int x,y,len;
    edge(int x, int y, int len):x(x),y(y),len(len){}
    bool operator <(const edge &e)const{
        return len>e.len;
    }
};

int n,m;
vector<vector<int>> g;
int x11,y11,x2,y2;
bool valid(int i, int j){
    return i>=0&&j>=0&&i<n&&j<m;
}
int dijkstra(){
    vector<vector<int>> dis(n,vector<int>(m,1e9));
    dis[x11][y11]=0;
    priority_queue<edge> q;
    q.push(edge(x11,y11,0));
    while(!q.empty()){
        const edge cur=q.top();
        q.pop();
        if(cur.len>dis[cur.x][cur.y]){
            continue;
        }
        for(int k=0; k<8; k++){
            int x=cur.x+dx[k];
            int y=cur.y+dy[k];
            if(valid(x,y)&&dis[x][y]>cur.len+(g[cur.x][cur.y]!=k)){
                dis[x][y]=cur.len+(g[cur.x][cur.y]!=k);
                q.push(edge(x,y,dis[x][y]));
            }
        }
    }
    return dis[x2][y2];
}
void Main(const int &T){
    cin>>n>>m;

    g=vector<vector<int>>(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin>>c;
            g[i][j]=c-'0';
        }
    }

    int q;
    cin>>q;
    while(q--){
        cin>>x11>>y11>>x2>>y2;
        x11--;
        y11--;
        x2--;
        y2--;
        cout<<dijkstra()<<endl;
    }
}
int main()
{
    file();
    fast();
    int T = 1;
    // cin>>T;
    for(int t=1; t<=T; t++){
        // cout<<"Case #"<< t <<": ";
        Main(t);
    }
}