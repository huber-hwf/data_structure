#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int l, r;
    while(cin>>l>>r){
        if(l>r) swap(l,r);
        long long odd=0, even=0;
        for(long long i=l; i<=r; i++){
            if(i>=0){
                if(i%2==1) odd+=(long long)i*i*i;
                else even+=(long long)i*i;
            }else{
                if(i%2==-1) odd+=(long long)i*i*i;
                else even+=(long long)i*i;
            }
        }
        cout<<even<<" "<<odd<<endl;
    }
    return 0;
}