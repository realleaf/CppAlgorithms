#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int cR1(map<int,int> list,int n) {
	if (n == 0) return 0;
	int q = INT_MIN;
	for (int i = 1; i <= n; ++i) q = max(q, list[i] + cR1(list,n - i));
	return q;
}
vector<int> table1(99999, INT_MIN);
int cR2(map<int, int> list, int n) {
	if (table1[n] >= 0) return table1[n];// If exists, search from table
	if (n == 0) return table1[0] = 0;
	int q=INT_MIN;
	for (int i = 1; i <= n; ++i)q = max(q, list[i] + cR2(list, n - i));
	return table1[n]=q;//Store new value
}
vector<int> table2(99999, 0);
int cR3(map<int, int> list, int n) {
	for (int i = 1; i <= n; ++i) {
		int q = INT_MIN;
		for (int j = 1; j <= i; ++j) q = max(q, list[j] + table2[i - j]);
		table2[i] = q;
	}
	return table2[n];
}
int main() {
	map<int, int> list{ {1,1},{2,5},{3,8},{4,9},{5,10},{6,17},{7,17},{8,20},{9,24},{10,30} };
	cout<<cR3(list, 7);
}

