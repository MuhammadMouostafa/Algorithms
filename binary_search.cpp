#include <bits/stdc++.h>
using namespace std;

int n,a[1000000+5];
int binary_search(int val){
    int lo=1,hi=n;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(a[mid]==val)return mid;
        if(a[mid]<val){
            lo = mid + 1;
        }else {
            hi = mid - 1;
        }
    }
    return -1;
}  
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        cout<<binary_search(x)<<endl;
    }
}