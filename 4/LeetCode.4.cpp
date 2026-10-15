#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            vector<int> temp=nums1;
            nums1=nums2;
            nums2=temp;
        }
        int m=nums1.size();
        int n=nums2.size();
        int left=0;
        int right=m;
        int totalleft=m+(n-m+1)/2;
        while(left<right){
            int i=left+(right-left+1)/2;
            int j=totalleft-i;
            if(nums1[i-1]>nums2[j]){
                right=i-1;
            }else{
                left=i;
            }
        }
        int i=left;
        int j=totalleft-i;
        int nums1leftmax=i==0?-2e7:nums1[i-1];
        int nums1rightmin=i==m?2e7:nums1[i];
        int nums2leftmax=j==0?-2e7:nums2[j-1];
        int nums2rightmin=j==n?2e7:nums2[j];
        if((n+m)%2==1){
            return max(nums1leftmax,nums2leftmax);
        }
        else return (max(nums1leftmax,nums2leftmax)+min(nums1rightmin, nums2rightmin))*1.0/2;
    }
};