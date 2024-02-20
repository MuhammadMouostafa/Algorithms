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
#define EPS 1e-6
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
const int N = 1e6 + 10;
const int MOD = 1e9 + 7;

int n;
int s=0,sh=-1;
int a[N],b[N];
double probanility_to_have_num_students_in_the_team(int num){
        /*
            space = (s+sh)!/(n!*(s+sh-n)!)
            p = ( sh!/(i!*(sh-i)!) ) / space
        */

        int asz=0,bsz=0;
        
        for(int j=2; j<=n; j++)a[asz++]=j;
        for(int j=2; j<=s+sh-n; j++)a[asz++]=j;
        for(int j=2; j<=sh; j++)a[asz++]=j;

        for(int j=2; j<=s+sh; j++)b[bsz++]=j;
        for(int j=2; j<=num; j++)b[bsz++]=j;
        for(int j=2; j<=(sh-num); j++)b[bsz++]=j;

        double p=1;

        if(n>num){
            if(s<n-num){
                p=0;
            }else{
                for(int j=2; j<=s; j++)a[asz++]=j;
                for(int j=2; j<=(n-num); j++)b[bsz++]=j;
                for(int j=2; j<=(s-n+num); j++)b[bsz++]=j;
            }
        }


        int i=0,j=0;
        while(i<asz&&j<bsz){
            if(p<1){
                p*=a[i++];
            }else{
                p/=b[j++];
            }
        }
        
      
        while(i<asz){
            p*=a[i++];
        }
        while(j<bsz){
            p/=b[j++];
        }
        return p;
}
void Main(const int &T){
    int m,h;
    cin>>n>>m>>h;
    n--;
    for(int i=1; i<=m; i++){
        int x;
        cin>>x;
        if(i==h){
            sh+=x;
        }else{
            s+=x;
        }
    }
    if(s+sh<n){
        cout<<-1<<endl;
        return;
    }
    double ans=0;
    for(int i=1; i<=min(n,sh); i++){
        ans+=probanility_to_have_num_students_in_the_team(i);
    }
    
    cout<<fixed<<setprecision(6)<<ans<<endl;
}
int main()
{
    file();
    fast();
    int T = 1;
    // cin>>T;
    for(int t=1; t<=T; t++){
        // cout<<"Case "<< t <<":";
        Main(t);
    }
}