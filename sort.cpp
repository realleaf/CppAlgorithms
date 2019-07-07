#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> insertSort(vector<int> arr) {
	int  j, current;
	for (int i = 1; i < arr.size(); ++i) {
		current = arr[i], j = i;//save current value for it may be modified later
		while (--j >= 0 && (arr[j] > current));//select proper position
		arr.erase(arr.begin()+i);
		arr.insert(arr.begin()+1+j, current);//insert current to suitable position	
	}
	return arr;
}
void merge(vector<int> &a,int l,int m,int r) {
	vector<int> a1(a.begin() + l, a.begin() + m+1);
	vector<int> a2(a.begin() + m + 1, a.begin() + r + 1);
	vector<int> a3;
	int len1= m - l + 1, len2= r - m;
	bool flag = false;
	while (!a1.empty() || !a2.empty()) {
		if (a1.empty()) (a3.insert(a3.end(), a2.begin(), a2.end()), flag = true);
		if (a2.empty()) (a3.insert(a3.end(), a1.begin(), a1.end()), flag = true);
		if (flag) break;
		a3.push_back(min(*a1.begin(), *a2.begin()));
		*a1.begin() > * a2.begin() ? a2.erase(a2.begin()): a1.erase(a1.begin());	
	}
	a.erase(a.begin() + l, a.begin() + r+1);
	a.insert(a.begin() + l, a3.begin(), a3.end());
}
void mergeSort(vector<int> &a,int l,int r) {
	if (l < r) {
	int m = (l + r) / 2;
	mergeSort(a,l,m);
	mergeSort(a,m+1,r);
	merge(a, l,m,r);
	}
}
void exchange(vector<int>& arr, int i, int j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
int partition(vector<int>& arr, int p, int r) {
	int i = p - 1;
	for (int j = p; j < r; ++j) 
		if (arr[j] <= arr[r]) //The first divide value is the end of the array
			if (++i != j) 
				exchange(arr, i, j);
	exchange(arr, i + 1, r); // Put divide value to divide position
	return i + 1;
}
void quickSort(vector<int> &arr, int p,int r) {
	if (p < r) {
		int q = partition(arr, p, r);// Get the divide point
		quickSort(arr, p, q-1);// Deal with the left part
		quickSort(arr, q + 1, r);//Deal with the right part
	}
}
int main() {
	vector<int> a1{ 2,1,3,2,4,5,6,3,4,9,8,7,3,4,6,9};
	for (int i:insertSort(a1))cout << i << " ";
	cout<<endl;
	vector<int> a2{9,4,7,5,8,6,3,2,1,0};
	int len = a2.size();
	mergeSort(a2,0,len-1);
	for (int i : a2)cout << i << " ";
	cout<<endl;
	vector<int> a3{ 7,3,4,6,7,5,6,3,7,4,6,5 };
	quickSort(a3,0,a.size()-1);
	for (int i : a3)cout << i << " ";
	cout<<endl;
}
