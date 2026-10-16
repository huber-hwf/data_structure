#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int a=0; a<n-3; a++){
            long long x=nums[a];
            if(a>0&&nums[a]==nums[a-1]) continue;
            if(x+nums[a+1]+nums[a+2]+nums[a+3]>target) break;
            if(x+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            for(int b=a+1; b<n-2; b++){
                long long y=nums[b];
                if(b>a+1&&nums[b]==nums[b-1]) continue;
                if(x+y+nums[b+1]+nums[b+2]>target) break;
                if(x+y+nums[n-2]+nums[n-1]<target) continue;
                int c=b+1, d=n-1;
                while(c<d){
                    if((long long)x+y+nums[c]+nums[d]<target) c++;
                    if((long long)x+y+nums[c]+nums[d]>target) d--;
                    if((long long)x+y+nums[c]+nums[d]==target){
                        if(c<d)
                        ans.push_back({(int)x, (int)y, nums[c], nums[d]});
                        for(c++; c<d&&nums[c]==nums[c-1]; c++);
                        for(d--; c<d&&nums[d]==nums[d+1]; d--);
                    }
                }
            }
        }
        return ans;
    }
};