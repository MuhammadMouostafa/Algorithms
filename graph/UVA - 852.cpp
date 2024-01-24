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

int n=9;
vector<string> s;

bool valid(int i, int j){
    return i>=0&&j>=0&&i<n&&j<n;
}
map<char,int> player,cnt;
int sum=0;
void dfs(int i, int j){
    if(s[i][j]!='.'){
        player[s[i][j]]=1;
        return;
    }
    sum++;
    s[i][j]='#';
    for(int k=0; k<4; k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(valid(x,y)){
            dfs(x,y);
        }
    }
}
void Main(const int &T){
    s=vector<string>(n);
    cin>>s;
    cnt.clear();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(isalpha(s[i][j])){
                s[i][j]=toupper(s[i][j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(s[i][j]=='.'){
                player.clear();
                sum=0;
                dfs(i,j);
                if(player['O']&&!player['X']){
                    cnt['O']+=sum;
                }else if(!player['O']&&player['X']){
                    cnt['X']+=sum;
                }
            }else{
                cnt[s[i][j]]++;
            }
        }
    }
    cout<<"Black "<< cnt['X'] << " White " << cnt['O']<<endl;
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