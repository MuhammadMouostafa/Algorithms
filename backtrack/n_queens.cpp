#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> v;
vector<string> a;
int n;
bool valid(int i, int j, int row, int colmn, int diag1, int diag2) {
	return (!(row & (1 << i)))					// empty row
		&& (!(colmn & (1 << j)))				// empty column
		&& (!(diag1 & (1 << (i + j))))			// empty diagonal 1
		&& (!(diag2 & (1 << (i + n - j - 1))));	// empty diagonal 2
}
void solve_n_queens(int i, int j,int num, int row, int colmn, int diag1, int diag2) {
	if (num==n) {
		v.push_back(a);
		return;
	}
	if (i==n) {
		return;
	}
	int i2 = i, j2 = j + 1;
	if (j2 == n) {
		j2 = 0;
		i2++;
	}
	solve_n_queens(i2, j2, num, row, colmn, diag1, diag2);
 
	if (valid(i,j,row,colmn,diag1,diag2)) {
		a[i][j] = 'Q';
		solve_n_queens(i2, j2, num + 1, row | (1 << i), colmn | (1 << j), diag1 | (1 << (i + j)), diag2 | (1 << (i + n - j - 1)));
		a[i][j] = '.';
	}
} 
int main()
{
    cin >> n;
	a = vector<string>(n, string(n, '.'));
	solve_n_queens(0, 0, 0, 0, 0, 0, 0);
	sort(v.begin(),v.end());
	for (auto i : v) {
		for (auto j : i)
			cout << j << endl;

        cout<<endl;
	}
}