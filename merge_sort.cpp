#include <bits/stdc++.h>
using namespace std;

int a[1000000+5];
int b[1000000+5];
void merge_sort(int l , int r){
    if(l>=r)return;
    int mid=(l+r)/2;
    merge_sort(l, mid);
    merge_sort(mid+1,r);
    int i=l,j=mid+1,idx=l;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]){
            b[idx++]=a[i++];
        }else {
            b[idx++]=a[j++];
        }
    }

    while(i<=mid)b[idx++]=a[i++];
    while(j<=r)b[idx++]=a[j++];

    for(int k=l; k<=r; k++){
        a[k]=b[k];
    }
}  
int main()
{
    int n;  
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    merge_sort(0,n-1);
    for(int i=0; i<n; i++){
       cout<<a[i]<<(i==n-1?"\n":" ");
    }
}