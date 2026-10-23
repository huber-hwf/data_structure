#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    long double pcp;
    long double rate;
    int year;
    cin>>pcp>>rate>>year;
    long double sumA=pcp+(pcp*rate/100*year);
    long double sumB=pcp*pow(1+rate/100, year);
    cout<<fixed<<setprecision(2)<<sumA<<" ";
    cout<<fixed<<setprecision(2)<<sumB<<endl;
    cout<<fixed<<setprecision(2)<<(sumA>sumB)?sumA-sumB:sumB-sumA;
    cout<<endl<<sizeof(pcp)<<" "<<sizeof(rate)<<" "<<sizeof(year);
    return 0;
}