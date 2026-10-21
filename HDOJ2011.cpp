#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int m;
    vector<PII> n;
    while(cin>>m){
        n.clear();
        for(int j=1; j<=m; j++){
            int x;
            cin>>x;
            n.push_back({j, x});
        }
        vector<long double> ans(m);
        sort(n.begin(), n.end(), [](const PII& a, const PII& b){
            return a.second<b.second;
        });
        int pos=0;
        int sign=1;
        long double sum=1;
        int i=1;
        while(i<=n.back().second){
            if(i==n[pos].second){
                int temp=n[pos].second;
                while(n[pos].second==temp){
                    ans[n[pos].first-1]=sum;
                    pos++;
                }
            }
                sign*=-1;
                sum+=(long double)sign/++i;
        }
        for(int k=0; k<m; k++){
            cout<<fixed<<setprecision(2)<<ans[k]<<endl;
        }
    }
    return 0;
}