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
// #ifndef ONLINE_JUDGE
    freopen("street.in", "r", stdin);
    // freopen("output.out", "w", stdout);
// #endif
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

int n,l,u;
struct spot{
    double y1,y2,w;
    int k;
    spot(){
        w=u;
        k=1;
    }
    friend istream& operator >> (istream &in, spot &s){
        in >>s.y2>>s.w>>s.y1>>s.k;
        s.y2+=s.y1;
        return in;
    }  
    double get_min_dis(const spot &s){

        double x=(k==s.k)?0:max(0.0,u-w-s.w);
        double y;
        if(y1>s.y2){
            y=abs(y1-s.y2);
        }else if(y2<s.y1){
            y=abs(y2-s.y1);
        }else {
            y=0;
        }
        return sqrt(x*x+y*y);
    }
};
void Main(const int &T){
    cin>>n>>l>>u;
    vector<spot> spots(n+2);
    spots[0].y1=0;
    spots[0].y2=0;

    spots[n+1].y1=l;
    spots[n+1].y2=l;

    for(int i =1; i<=n; i++){
        cin>>spots[i];
    }
    
    vector<double> dis(n+2,1e9);
    dis[0]=0;
    priority_queue<pair<double,int>,vector<pair<double,int>>, greater<pair<double,int>>> q;
    q.push({0,0});
    while(!q.empty()){
        auto cur=q.top();
        q.pop();
        if(cur.first>dis[cur.second])continue;
        for(int i=1; i<=n+1; i++)
        if(dis[i]>cur.first+spots[cur.second].get_min_dis(spots[i])){
            dis[i]=cur.first+spots[cur.second].get_min_dis(spots[i]);
            q.push({dis[i],i});
        }
    }
    cout<<fixed<<setprecision(6)<<dis[n+1]<<endl;   
}
int main()
{
    file();
    fast();
    int T = 1;
    cin>>T;
    for(int t=1; t<=T; t++){
        // cout<<"Case #"<< t <<": ";
        Main(t);
    }
}