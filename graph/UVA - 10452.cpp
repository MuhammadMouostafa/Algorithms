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

int dx[] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
string dir[] = {"right", "left", "forth"};

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

vector<string> a;
int n,m;
string valid_cells="IEHOVA#@";
bool valid(int i, int j){
    return i>=0&&j>=0&&i<n&&j<m&&valid_cells.find(a[i][j])!=string::npos;
}

void Main(const int &T){
    cin>>n>>m;
    a.resize(n);
    cin>>a;
    vector<vector<int>> d(n,vector<int>(m,1e9));
    vector<vector<int>> direction(n,vector<int>(m));
    queue<pii> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m;  j++){
            if(a[i][j]=='@'){
                q.push({i,j});
                d[i][j]=0;
            }
        }
    }
    while(!q.empty()){
        pii cur=q.front();
        q.pop();
        for(int k=0; k<3; k++){
            int x = cur.first+dx[k];
            int y = cur.second+dy[k];
            if(valid(x,y)&&d[x][y]>d[cur.first][cur.second]+1){
                d[x][y]=d[cur.first][cur.second]+1;
                direction[x][y]=k;
                q.push({x,y});
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m;  j++){
            if(a[i][j]=='#'){
            
                vector<string> path;
                while(a[i][j]!='@'){
                    int k=direction[i][j];
                    path.push_back(dir[k]);
                    k=(k%2==0)?k+1:k-1;
                    i+=dx[k];
                    j+=dy[k];
                }

                reverse(path.begin(),path.end());
                cout<<path<<endl;
            
                return;
            }
        }
    }
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