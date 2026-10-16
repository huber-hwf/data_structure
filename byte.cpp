#include<iostream>
using namespace std;
int main(){
    cout<<"int\t\t"<<sizeof(int)<<endl;
    cout<<"long int\t"<<sizeof(long)<<endl;
    cout<<"long long int\t"<<sizeof(long long)<<endl;
    cout<<"__int64\t\t"<<sizeof(__int64)<<endl;
    cout<<"float\t\t"<<sizeof(float)<<endl;
    cout<<"double\t\t"<<sizeof(double)<<endl;
    cout<<"long double\t"<<sizeof(long double)<<endl;
    cout<<"char\t\t"<<sizeof(char)<<endl<<endl;
    return 0;
}