#include <iostream>
using namespace std;
int binarySearch(int* arr,int len, int target) { // Old problem, how to remove the length as a parameter? How?(when array type should be kept as a pointer)
	int l = 0, r = len - 1, m = (l + r) / 2;
	while (l < r) {
		if (r - l == 1) return arr[r] == target ? r : arr[l] == target?l:-1;// Reach the last step. This means the bound
		else {
			if (arr[m] == target) return m; // Get answer smoothly
			else arr[m] < target? (l = m, m = (l + r) / 2):(r = m, m = (l + r) / 2);// Faild to find and do next round
		}
	}
}
int main() {
	int a[] = { 1,3,5,6,8, 10,15,36,94};
	int len = end(a) - begin(a);
	cout << binarySearch(a, len, 15);//6
}
