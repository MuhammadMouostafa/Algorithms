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

struct mine
{
    int x,y,d;

    friend istream& operator>>(istream& is, mine& in_mine) {
        is >> in_mine.x;
        is >> in_mine.y;
        is >> in_mine.d;
        return is;
    }  
   
    bool can_explode(mine &other){
        return d>=2*abs(x-other.x)&&d>=2*abs(y-other.y);
    }
};

vector<vector<int>> adj;
vector<bool> exploded;
stack<int> explosion_order;
bool topological_sort;
void explode(int mine){
    exploded[mine]=true;
    for(int ch:adj[mine]){
        if(!exploded[ch]){
            explode(ch);
        }
    }
    if(topological_sort){
        explosion_order.push(mine);
    }
}
void Main(const int &T){
    int n;
    cin>>n;
    vector<int> in_edges(n);
    vector<mine> mines(n);
    cin>>mines;
    adj=vector<vector<int>>(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j&&mines[i].can_explode(mines[j])){
                in_edges[j]++;
                adj[i].push_back(j);
            }
        }
    }

    topological_sort = true;
    exploded=vector<bool>(n);
    for(int i=0; i<n; i++){
        if(!exploded[i]){
            explode(i);
        }
    }
    topological_sort = false;
    exploded=vector<bool>(n);
    int explosions_count=0;
    while(!explosion_order.empty()){
        if(!exploded[explosion_order.top()]){
            explosions_count++;
            explode(explosion_order.top());
        }
        explosion_order.pop();
    }
    cout<<explosions_count<<endl;

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