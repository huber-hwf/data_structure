#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> avgs(n,-1);
        int w=2*k+1;
        long long sum=0;
        if(w>n) return avgs;
        for(int i=0; i<w; i++) sum+=nums[i];
        avgs[k]=sum/w;
        for(int i=w; i<n; i++){
            sum+=nums[i]-nums[i-w];
            avgs[i-k]=sum/w;
        }
        return avgs;
    }
};