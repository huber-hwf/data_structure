#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        long long s=0, ans=-2e9, temp=0;
        for(int i=0; i<grumpy.size(); i++){
            s+=grumpy[i]==1?0:customers[i];
            temp+=grumpy[i]==1?customers[i]:0;
            if(i==minutes-1) ans=max(ans, temp);
            if(i>minutes-1){
                if(grumpy[i-minutes]==1) temp-=customers[i-minutes];
                ans=max(ans, temp);
            }
        }
        return s+ans;
    }
};