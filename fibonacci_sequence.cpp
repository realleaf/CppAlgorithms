#include <iostream>
using namespace std;
//Recusive method
double fs1(int n) {
	return n == 1 || n == 2 ? 1 : fs1(n - 1) + fs1(n - 2);
}
//Improved recusive method
double* table = new double[99999]();
double fs2(int n) {
	return table[--n] == 0 ? table[n] = fs2(n) + fs2(n - 1) : table[n];
}
//Iteration method
double fs3(int n) {
	double a = 1, b = 1, c = 0;// a,b previous two state;c currrent state
	for (int i = 3; i <= n; ++i) (c = a + b, a = b, b = c);
	return c;
}
double fs4(int n) {
	return floor(pow((1 + sqrt(5)) / 2, n) / sqrt(5) + 0.5);
}
int main() {
	table[0] = table[1] = 1;
	int n = 10;
	cout << fs4(n);
	delete[] table;
}
