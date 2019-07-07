#include <iostream>
#include <iomanip>
using namespace std;
double getPi(long End){
    double pi=0;
    long denominator=-1,numerator=-4,i=0;
    while(i++<End)pi+=(numerator*=-1)*1./(denominator+=2);//Leibniz formula
    return pi;
}
int main()
{
    double pi=getPi(9999999999);//it costs much time
    cout<<setprecision(50)<<pi;
    //3.1415926503687150450616627495037391781806945800781
}
