#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool Isprime(int n){
    if(n<2) return false;
    for(int i=2; i*i<n; i++){
        if(n%i==0) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int x, y;
    while(cin>>x>>y){
        if(x>y) swap(x, y);
        if(x==y) break;
        int prime=1;
        for(int i=x; i<=y; i++){
            int num=i*i+i+41;
            if(!Isprime(num)){
                prime=0;
            }
        }
        if(prime)
        cout<<"OK"<<endl;
        else
        cout<<"Sorry"<<endl;
    }
    return 0;
}