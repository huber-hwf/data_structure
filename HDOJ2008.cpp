#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int count;
    while(cin>>count){
        if(count==0) break;
        int pos=0, zero=0, neg=0;
        for(int i=0; i<count; i++){
            double x;
            cin>>x;
            if(x<0) neg++;
            else if(x==0) zero++;
            else pos++;
        }
        cout<<neg<<" "<<zero<<" "<<pos<<endl;
    }
    return 0;
}