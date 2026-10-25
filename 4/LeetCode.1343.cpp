#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans=0;
        int sum=0;
        for(int i=0, j=0; i<arr.size(); i++){
            sum+=arr[i];
            if(i>=k-1){
                if(i>k-1) sum-=arr[j++];
                double ave=sum*1.0/k;
                if(ave>=threshold) ans++;
            }
        }
        return ans;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<int> a={1,2,3,4,5};
    Solution s;
    int t, k;
    while(cin>>t>>k)
    cout<<s.numOfSubarrays(a, k, t)<<endl;
    return 0;
}