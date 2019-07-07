#include <iostream>
#include <vector>
using namespace std;
struct tower{vector<int> A,B,C;};
void hanoi(int plates,vector<int> &A,vector<int> &B,vector<int> &C){
    //position:A->C,B is temporary state
    if(plates==1) (C.push_back(A.back()),A.pop_back());//A->C
    else{
        hanoi(plates-1,A,C,B);//move n-1 plates from to A to B
        hanoi(1,A,B,C);//move the surplus 1 plate(the bottom one) from A to C
        hanoi(plates-1,B,A,C);//move the n-1 plates from B to C
    }
}
int main()
{
    tower t;
    int plates=10,i=plates;
    fill_n(back_inserter(t.A),plates,0);
    while(i>0) t.A[plates-i]=i--;
    hanoi(plates,t.A,t.B,t.C);
    cout<<t.A.size()<<" "<<t.B.size()<<endl;
    for(int j=0;j<t.C.size();++j)cout<<t.C[j]<<" ";
}