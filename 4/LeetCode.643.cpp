#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans=-2e5;
        int sum=0;
        for(int i=0, j=0; i<nums.size(); i++){
            sum+=nums[i];
            if(i>=k-1){
                if(i>k-1)sum-=nums[j++];
                ans=max(ans, (double)sum/k);
            }
        }
        return ans;
    }
};