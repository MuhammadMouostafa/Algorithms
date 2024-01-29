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
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;

struct edge
{
    int to;
    double len,tem;
    edge(int to, double len, double tem):to(to),len(len),tem(tem){}
    bool operator <(const edge &e)const{
        return len>e.len;
    }
};

int n,src,dest;
vector<vector<edge>> adj;
// bool bfs(double t){
//     vector<bool> vis(n);
//     queue<int> q;
//     vis[src]=1;
//     q.push(src);
//     while(!q.empty()){
//         int cur = q.front();
//         q.pop();
//         if(cur==dest)return true;
//         for(edge e:adj[cur]){
//             if(e.tem<=t&&!vis[e.to]){
//                 vis[e.to]=true;
//                 q.push(e.to);
//             }
//         }
//     }
//     return false;
// }
double get_min_max_tempreture_flyed(){
    vector<vector<double>> mnmx(n,vector<double>(n,1e9));
    for(int i=0; i<n; i++){
        for(edge e:adj[i]){
            mnmx[i][e.to]=min(mnmx[i][e.to],e.tem);
        }
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mnmx[i][j]=min(mnmx[i][j],max(mnmx[i][k],mnmx[k][j]));
            }
        }
    }

    return mnmx[src][dest];

    // double lo=0,hi=40,ans=1e9;
    // while(lo<=hi){
    //     double mid=(lo+hi)/2;
    //     if(bfs(mid)){
    //         ans=mid;
    //         hi=mid-0.1;
    //     }else{
    //         lo=mid+0.1;
    //     }
    // }
    // return ans;
}
void dijkstra(){
    double t = get_min_max_tempreture_flyed();
    vector<double> dis(n,1e9);
    vector<int> prev(n,-1);
    dis[src]=0;
    priority_queue<edge> q;
    q.push(edge(src,0,0));
    while(!q.empty()){
        edge cur=q.top();
        q.pop();
        if(cur.len>dis[cur.to]){
            continue;
        }
        for(edge e:adj[cur.to]){
            if(e.tem<=t&&dis[e.to]>cur.len+e.len){
                dis[e.to]=cur.len+e.len;
                q.push(edge(e.to,dis[e.to],e.tem));
                prev[e.to]=cur.to;
            }
        }
    }
    vector<int> path;
    int d=dest;
    while(d!=-1){
        path.push_back(d+1);
        d=prev[d];
    }
    reverse(path.begin(),path.end());
    cout<<path<<endl;
    cout<<fixed<<setprecision(1)<<dis[dest]<<" "<<t<<endl; 
}
void Main(const int &T){
    int m;
    while(cin>>n>>m>>src>>dest){
        src--;
        dest--;
        adj=vector<vector<edge>>(n);
        while(m--){
            int u,v;
            double len,tem;
            cin>>u>>v>>tem>>len;
            u--;
            v--;
            adj[u].push_back(edge(v,len,tem));
            adj[v].push_back(edge(u,len,tem));
        }
        dijkstra();
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