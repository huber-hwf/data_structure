#include<iostream>
#include<iomanip>
using namespace std;
double sqrt(double n){
    double l=0, r=n;
    while(r-l>1e-11){
        double mid=(l+r)/2;
        if(mid<=n/mid) l=mid;
        else r=mid;
    }
    return l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    while(cin>>n>>m){
        double sum=0;
        double temp=n;
        for(int i=0; i<m; i++){
            sum+=temp;
            temp=sqrt(temp);
        }
        cout<<fixed<<setprecision(2)<<sum<<endl;
    }
    return 0;
}