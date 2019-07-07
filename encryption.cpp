#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
using namespace std;
struct Pair {
	string pd;
	int rd;
};
Pair encryption(string origin) {
	Pair p;
	int i = 0, length = origin.length();
	//p.pd = new char[length]();
	p.rd = rand();
	while (i < length)p.pd += (char)(origin[i++] ^ p.rd);
	return p;
}
string decryption(Pair pp) {
	int i = 0, length = pp.pd.length();
	string origin;
	while (i < length)origin += (char)(pp.pd[i++] ^ pp.rd);
	return origin;
}
int main()
{
	srand((int)time(0));
	string data = "hdssg83974#$@%$";
	Pair encrypt = encryption(data);
	cout << "after encryption" << endl;
	cout << encrypt.pd << endl;//<<encrypt.rd<<endl;
	string decrypt = decryption(encrypt);
	cout << "after decryption" << endl;
	cout << decrypt;
}
