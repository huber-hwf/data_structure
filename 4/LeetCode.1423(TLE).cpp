#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int m=cardPoints.size()-k;
        long long s=0, ans=0;
        for(int i=0; i<k; i++){
            s+=cardPoints[i];
        }
        if(cardPoints.size()==k) return s;
        for(int i=m-1, j=0; i<cardPoints.size(); i++, j++){
            int l=j-1, r=i+1;
            long long temp=0;
            while(l>=0) temp+=cardPoints[l--];
            while(r<cardPoints.size()) temp+=cardPoints[r++];
            ans=max(temp, ans);
        }
        return ans;
    }
};