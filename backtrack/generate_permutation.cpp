#include <bits/stdc++.h>
using namespace std;

int n;
void backTrack(int mask,vector<int> a){
	if (a.size() == n){
		for (int i = 0; i < n; i++)
			cout << a[i] << (i + 1 == n ? "\n" : " ");
		return;
	}
	for (int i = 1; i <= n; i++)
	if(!(mask&(1<<i))){
		mask |= (1 << i);
		a.push_back(i);
		backTrack(mask, a);
		a.pop_back();
		mask ^= (1 << i);
	}
}
int main()
{
    // Given an integer N, print all the permutations of numbers from 1 to N.
    cin>>n;
	backTrack(0, {});
}