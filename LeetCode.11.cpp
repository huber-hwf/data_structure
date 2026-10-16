#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size();
        int l=0, r=len-1;
        int ans=min(height[l], height[r])*r;
        int lm=height[l], rm=height[r];
        while(l!=r){
            if(lm<rm){
                l++;
                if(lm<height[l]){
                    lm=height[l];
                    ans=max(ans, min(height[l], rm)*(r-l));
                }
            }
            else{
                r--;
                if(rm<height[r]){
                    rm=height[r];
                    ans=max(ans, min(height[r], lm)*(r-l));
                }
            }
        }
        return ans;
    }
};