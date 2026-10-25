#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avgs;
        unsigned long long sum=0;
        for(int i=0,j=0; i<nums.size(); i++){
            if(i<k){
                avgs.push_back(-1);
                sum+=nums[i];
            }
            else if(i==k){
                int t=i+k<nums.size()?i+k:nums.size()-1;
                while(t>=i) sum+=nums[t--];
                if(i+k<nums.size()) avgs.push_back(sum/(2*k+1));
                else avgs.push_back(-1);
            }else{
                if(i+k<nums.size()){
                    sum+=nums[i+k];
                    sum-=nums[j++];
                    avgs.push_back(sum/(2*k+1));
                }else{
                    avgs.push_back(-1);
                }
            }
        }
        return avgs;
    }
};