#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m, n;
    vector<int> ans;
    while(cin>>m>>n){
        if(m>n) swap(m,n);
        ans.clear();
        for(int i=m; i<=n; i++){
            long long one=i%10;
            long long ten=i/10%10;
            long long hun=i/100;
            if(one*one*one+ten*ten*ten+hun*hun*hun==i)
            ans.push_back(i);
        }
        if(ans.size()==0) cout<<"no"<<endl;
        else{
            for(int i=0; i<ans.size(); i++){
                cout<<ans[i];
                if(i<ans.size()-1) cout<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}