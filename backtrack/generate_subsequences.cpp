#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> a;
void backTrack(int  i, string s2){
	if (i == s.size()) {
		if (!s2.empty()) {
			a.push_back(s2);
		}
		return;
	}
	backTrack(i + 1, s2);
	backTrack(i + 1, s2 + s[i]);
}
int main()
{
    // Given string S print all nonempty subsequences of it
    cin >> s;
	backTrack(0, "");
	sort(a.begin(),a.end());
	for (string s : a) {
		cout << s << "\n";
	}
}